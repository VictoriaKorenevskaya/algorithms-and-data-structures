
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Graph {
private:
    int A;
    int** matrix;

public:
    Graph(int n) : A(n) {
        matrix = new int* [A];
        for (int i = 0; i < A; i++) {
            matrix[i] = new int[A];
        }
        initializeMatrix();
    }

    ~Graph() {
        for (int i = 0; i < A; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void initializeMatrix() {
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < A; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int n, int m) {
        matrix[n - 1][m - 1] = 1;
        matrix[m - 1][n - 1] = 1;
    }

    void printMatrix(ofstream& outFile) {
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < A; j++) {
                outFile << matrix[i][j] << " ";
            }
            outFile << endl;
        }
    }
};

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int A, B;
    inFile >> A >> B;

    Graph graph(A);

    int n, m;
    for (int i = 0; i < B; i++) {
        inFile >> n >> m;
        graph.addEdge(n, m);
    }

    graph.printMatrix(outFile);

    inFile.close();
    outFile.close();

    return 0;
}