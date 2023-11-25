
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Roads {
public:
    Roads(long long size);

    long long DisjointSet(long long x);
    void Union(long long x, long long y, long long& currentNum);

private:
    vector<long long> root;
    vector<long long> size;
};

Roads::Roads(long long size) {
    root.resize(size + 1);
    this -> size.resize(size + 1, 1);

    for (int i = 1; i <= size; i++) {
        root[i] = i;
    }
}

long long Roads::DisjointSet(long long x) {
    vector<long long> vec;
    while (x != root[x]) {
        vec.push_back(x);
        x = root[x];
    }

    for (long long temp : vec) {
        root[temp] = x;
    }

    return x;
}

void Roads::Union(long long x, long long y, long long& currentNum) {
    x = DisjointSet(x);
    y = DisjointSet(y);

    if (x != y) {
        root[y] = x;
        size[x] += size[y];
        currentNum--;
    }
}

class Solver {
public:
    Solver(const string& inputFileName, const string& outputFileName);

    void Solve();

private:
    ifstream inFile;
    ofstream outFile;
    long long numOfElements, numOfQueries;
    long long currentNum;
    Roads disjointSet;
};

Solver::Solver(const string& inputFileName, const string& outputFileName)
    : inFile(inputFileName), outFile(outputFileName), disjointSet(0) {}

void Solver::Solve() {
    inFile >> numOfElements >> numOfQueries;
    disjointSet = Roads(numOfElements);
    currentNum = numOfElements;

    for (int i = 0; i < numOfQueries; i++) {
        long long endpoint1;
        long long endpoint2;
        inFile >> endpoint1 >> endpoint2;

        if (disjointSet.DisjointSet(endpoint1) != disjointSet.DisjointSet(endpoint2)) {
            disjointSet.Union(endpoint1, endpoint2, currentNum);
        }

        outFile << currentNum << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    ios::sync_with_stdio(false);
    Solver solver("input.txt", "output.txt");
    solver.Solve();
    return 0;
}