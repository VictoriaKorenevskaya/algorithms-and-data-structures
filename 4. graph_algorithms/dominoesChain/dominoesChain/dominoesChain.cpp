#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    vector<bool> added;

public:
    Graph(int size) : adjacencyMatrix(size, vector<int>(size, 0)), added(size, false) {}

    void addEdge(int p1, int p2) {
        added[p1] = added[p2] = true;
        adjacencyMatrix[p1][p2] = adjacencyMatrix[p2][p1] += 1;
    }

    int getSize() const {
        return adjacencyMatrix.size();
    }

    const vector<int>& neighbors(int node) const {
        return adjacencyMatrix[node];
    }

    bool isVisited(int node) const {
        return added[node];
    }
};

class algor {
private:
    vector<bool> visitedNodes;

public:
    algor(int size) : visitedNodes(size, false) {}

    void DFS(const Graph& graph, int start) {
        visitedNodes[start] = true;
        for (int i = 0; i < graph.getSize(); i++)
            if (graph.isVisited(i) && graph.neighbors(start)[i] && !visitedNodes[i])
                DFS(graph, i);
    }

    bool isConnected(const Graph& graph) {
        for (int i = 0; i < graph.getSize(); i++) {
            if (graph.isVisited(i)) {
                DFS(graph, i);
                break;
            }
        }

        for (int i = 0; i < graph.getSize(); i++) {
            if (graph.isVisited(i) && !visitedNodes[i]) {
                return false;
            }
        }

        return true;
    }

    bool check(const Graph& graph) {
        for (int i = 0; i < graph.getSize(); i++) {
            if (graph.isVisited(i)) {
                int summary = 0;

                for (int j = 0; j < graph.getSize(); j++) {
                    if (i == j){
                        summary += 2 * graph.neighbors(i)[j];
                    }      
                    else{ 
                        summary += graph.neighbors(i)[j]; 
                    }
                       
                }

                if (summary % 2 != 0) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (inFile.is_open()) {
        int N;
        inFile >> N;

        Graph graph(7);
        algor Algorithm(7);

        int k = 0, m = 0;
        for (int i = 0; i < N; i++) {
            inFile >> k >> m;
            graph.addEdge(k, m);
        }

        bool check = Algorithm.isConnected(graph) && Algorithm.check(graph);

        outFile << (check ? "Yes" : "No");
    }

    inFile.close();
    outFile.close();

    return 0;
}
