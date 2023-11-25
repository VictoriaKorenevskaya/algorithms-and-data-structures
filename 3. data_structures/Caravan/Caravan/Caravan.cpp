
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class MazeSolver {
private:
    int mazeSize;
    int x1, y1, x2, y2;
    vector<vector<long long>> maze;
    vector<vector<long long>> lines;

public:
    MazeSolver(const string& inFileName, const string& outFileName) {
        ifstream inFile(inFileName);
        inFile >> mazeSize;

        maze.resize(mazeSize, vector<long long>(mazeSize));
        lines.resize(mazeSize, vector<long long>(mazeSize, 0));

        inFile >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;

        for (int i = 0; i < mazeSize; i++) {
            for (int j = 0; j < mazeSize; j++) {
                inFile >> maze[i][j];
            }
        }
    }

    void solveMaze() {
        queue<int> Queue;
        Queue.push(x1);
        Queue.push(y1);

        lines[x1][y1] = maze[x1][y1];

        while (!Queue.empty()) {
            int i = Queue.front();
            Queue.pop();
            int j = Queue.front();
            Queue.pop();

            if (i + 1 >= 0 && i + 1 < mazeSize && maze[i + 1][j] < maze[i][j] && lines[i + 1][j] == 0) {
                Queue.push(i + 1);
                Queue.push(j);
                lines[i + 1][j] = maze[i + 1][j];
            }

            if (i - 1 >= 0 && i - 1 < mazeSize && maze[i - 1][j] < lines[i][j] && lines[i - 1][j] == 0) {
                Queue.push(i - 1);
                Queue.push(j);
                lines[i - 1][j] = maze[i - 1][j];
            }

            if (j + 1 >= 0 && j + 1 < mazeSize && maze[i][j + 1] < lines[i][j] && !lines[i][j + 1]) {
                Queue.push(i);
                Queue.push(j + 1);
                lines[i][j + 1] = maze[i][j + 1];
            }

            if (j - 1 >= 0 && j - 1 < mazeSize && maze[i][j - 1] < lines[i][j] && !lines[i][j - 1]) {
                Queue.push(i);
                Queue.push(j - 1);
                lines[i][j - 1] = maze[i][j - 1];
            }
        }
    }

    void writeOutput(const string& outFileName) {
        ofstream outFile(outFileName);

        for (const auto& row : lines) {
            for (const auto& value : row) {
                outFile << value;

                if (&value != &row.back()) {
                    outFile << " ";
                }
            }

            if (&row != &lines.back()) {
                outFile << endl;
            }
        }
    }
};

int main() {
    MazeSolver mazeSolver("in.txt", "out.txt");
    mazeSolver.solveMaze();
    mazeSolver.writeOutput("out.txt");

    return 0;
}