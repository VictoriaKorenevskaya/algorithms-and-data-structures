#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Matrixx {
public:
    Matrixx(const string& inFileName, const string& outFileName);
    void read();
    void calculate();
    void result();
    void initializeMatrix();
private:
    int x, y, z;
    string N, M;
    vector<vector<int>> Matrix;
    string inFileName;
    string outFileName;
};

Matrixx::Matrixx(const string& inFileName, const string& outFileName)
    : inFileName(inFileName), outFileName(outFileName) {}

void Matrixx::read() {
    ifstream inFile(inFileName);

    inFile >> x >> y >> z;
    getline(inFile, N);
    getline(inFile, N);
    getline(inFile, M);

    inFile.close();
}

void Matrixx::initializeMatrix() {
    int n = N.size() + 1;
    int m = M.size() + 1;

    Matrix.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        Matrix[i][0] = i * x;
    }

    for (int i = 0; i < m; i++) {
        Matrix[0][i] = i * y;
    }
}

void Matrixx::calculate() {
    int n = N.size() + 1;
    int m = M.size() + 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int Change;
            if (N[i - 1] != M[j - 1]) {
                Change = Matrix[i - 1][j - 1] + z;
            }
            else {
                Change = Matrix[i - 1][j - 1];
            }

            int minimum = Matrix[i - 1][j] + x;
            minimum = min(minimum, Change);
            minimum = min(minimum, Matrix[i][j - 1] + y);

            Matrix[i][j] = minimum;
        }
    }
}

void Matrixx::result() {
    ofstream outFile(outFileName);
    outFile << Matrix[N.size()][M.size()];
    outFile.close();
}

int main() {
    Matrixx calculator("in.txt", "out.txt");
    calculator.read();
    calculator.initializeMatrix();
    calculator.calculate();
    calculator.result();

    return 0;
}