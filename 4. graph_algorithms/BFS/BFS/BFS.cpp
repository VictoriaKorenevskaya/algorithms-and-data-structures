
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class MazeSolver {
public:
    int mazeSize;
    vector<vector<int>> matrix;

    MazeSolver(int size) : mazeSize(size), matrix(size, vector<int>(size, 0)) {}

    void readInput(const string& filename) {
        ifstream inFile(filename);
        inFile >> mazeSize;

        matrix.resize(mazeSize, vector<int>(mazeSize, 0));

        for (int i = 0; i < mazeSize; ++i) {
            for (int j = 0; j < mazeSize; ++j) {
                inFile >> matrix[i][j];
            }
        }

        inFile.close();
    }
};

class solveMaze {
public:
    vector<int> label;
    int uniqueLabel;

    solveMaze(int vertices) : label(vertices, 0), uniqueLabel(1) {}

    void breadthFirstSearch(int start, const MazeSolver& maze) {
        queue<int> Queue;

        label[start] = uniqueLabel++;
        Queue.push(start);

        while (!Queue.empty()) {
            int n = Queue.front();
            Queue.pop();


          for (int j = 0; j < maze.matrix[n].size(); ++j) {
             if (maze.matrix[n][j] == 1 && label[j] == 0) {
                    Queue.push(j);
                    label[j] = uniqueLabel++;
             }
          }
        }
    }

    void identifyConnectComp(const MazeSolver& maze) {
        for (int i = 0; i < maze.mazeSize; ++i) {
            if (label[i] == 0) {
                breadthFirstSearch(i, maze);
            }
        }
    }

    void writeOutput(const string& filename) {
        ofstream outFile(filename);

        for (int i : label) {
            outFile << i << " ";
        }
        outFile.close();
    }
};

int main() {
    MazeSolver maze(0);

    maze.readInput("input.txt");

    solveMaze components(maze.mazeSize);
    components.identifyConnectComp(maze);

    components.writeOutput("output.txt");

    return 0;
}