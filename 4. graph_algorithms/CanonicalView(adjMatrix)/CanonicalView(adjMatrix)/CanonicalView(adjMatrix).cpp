

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Matrixxx {
public:
    Matrixxx(const string& inFileName, const string& outFileName);
    void processMatrix();

private:
    ifstream inFile;
    ofstream outFile;
    int edges;
    vector<int> matrixP;
};

Matrixxx::Matrixxx(const string& inFileName, const string& outFileName)
    : inFile(inFileName), outFile(outFileName) {}

void Matrixxx::processMatrix() {
  
    inFile >> edges;
    matrixP.resize(edges, 0);
    int p;

    for (int i = 0; i < edges; i++) {
        for (int j = 0; j < edges; j++) {
            inFile >> p;

            if (p == 1) {
                cout << p;
                matrixP[j] = i + 1;
            }

        }
    }

    for (int i = 0; i < edges; i++) {
        outFile << matrixP[i] << " ";
    }
}

int main() {
    Matrixxx processor("input.txt", "output.txt");
    processor.processMatrix();

    return 0;
}