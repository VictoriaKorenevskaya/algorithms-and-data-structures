
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class HuffmanCoding {
private:
    int n;
    vector<long long> travers1;
    vector<long long> travers2;
    long long sum;

public:
    HuffmanCoding() : n(0), sum(0) {}

    void readInput(const string& inputFile) {
        ifstream inFile(inputFile);
        inFile >> n;
        travers1.resize(n);
        for (int i = 0; i < n; ++i) {
            inFile >> travers1[i];
        }
        inFile.close();
    }

    void calculateHuffman() {
        long long i = 0, j = 0;
        long long x, y;
        long long size = n - 1;

        x = travers1[0] + travers1[1];
        sum += x;
        travers2.push_back(x);
        i = 2;

        size_t h = 1;
        while (h < size) {
            long long x, y;

            if (i == n || (j < travers2.size() && travers1[i] > travers2[j])) {
                x = travers2[j++];
            }
            else {
                x = travers1[i++];
            }

            if (i == n || (j < travers2.size() && travers1[i] > travers2[j])) {
                y = travers2[j++];
            }
            else {
                y = travers1[i++];
            }

            sum += x + y;
            travers2.push_back(x + y);

            ++h;
        }
    }

    void writeOutput(const string& outputFile) {
        ofstream outFile(outputFile);
        outFile << sum;
        outFile.close();
    }
};

int main() {
    HuffmanCoding huffman;
    huffman.readInput("huffmanin.txt");
    huffman.calculateHuffman();
    huffman.writeOutput("huffmanout.txt");

    return 0;
}