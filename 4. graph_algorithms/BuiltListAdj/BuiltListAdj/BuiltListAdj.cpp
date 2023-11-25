

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Graph {
public:
    Graph(const string& inFileName, const string& outFileName);
    void read();
    void write();

private:
    ifstream inFile;
    ofstream outFile;
    int length;
    int ribs;
    vector<vector<int>> nodes;
};

Graph::Graph(const string& inFileName, const string& outFileName)
    : inFile(inFileName), outFile(outFileName) {}

void Graph::read() {
    inFile >> length >> ribs;
    nodes.resize(length);

    for (int i = 0; i < ribs; i++) {
        int n1, n2;
        inFile >> n1 >> n2;
        nodes[n1 - 1].push_back(n2);
        nodes[n2 - 1].push_back(n1);
    }
}

void Graph::write() {
    for (int i = 0; i < length; i++) {
        outFile << nodes[i].size() << " ";
        for (int j = nodes[i].size() - 1; j >= 0; j--) {
            outFile << nodes[i][j] << " ";
        }
        outFile << "\n";
    }
}

int main() {
    Graph graph("input.txt", "output.txt");
    graph.read();
    graph.write();

    return 0;
}