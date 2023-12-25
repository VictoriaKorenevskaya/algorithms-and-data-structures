#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(const string& filename);
    void write(const string& outFilename);

private:
    void DFS(int currentVertex, vector<int>& unique);

    int point = 1;
    vector<vector<int>> adjacencyMatrix;
    vector<int> unique;
};

Graph::Graph(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    int n;
    inFile >> n;

    adjacencyMatrix.resize(n, vector<int>(n));
    unique.resize(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> adjacencyMatrix[i][j];
        }
    }

    inFile.close();
}

void Graph::DFS(int currentVertex, vector<int>& unique) {
    for (int j = 0; j < adjacencyMatrix[currentVertex].size(); j++) {
        if (adjacencyMatrix[currentVertex][j] == 1 && unique[j] == 0) {
            unique[j] = point++;
            DFS(j, unique);
        }
    }
}

void Graph::write(const string& outFilename) {
    ofstream outFile(outFilename);
 
    for (int i = 0; i < unique.size(); i++) {
        if (unique[i] == 0) {
            unique[i] = point++;
            DFS(i, unique);
        }
    }

    for (int i : unique) {
        outFile << i << " ";
    }

    outFile.close();
}

int main() {
    Graph graph("input.txt");
    graph.write("output.txt");

    return 0;
}