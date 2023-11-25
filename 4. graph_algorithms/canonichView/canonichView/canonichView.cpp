

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class FileReader {
public:
    FileReader(const string& fileName) {
        file.open(fileName);
    }

    int read() {
        int value;
        file >> value;
        return value;
    }

    void readPairs(vector<pair<int, int>>& pairs, int count) {
        pairs.resize(count - 1);
        for (int i = 0; i < count - 1; ++i) {
            file >> pairs[i].first >> pairs[i].second;
        }
    }

    ~FileReader() {
        file.close();
    }

private:
    ifstream file;
};

class FileWriter {
public:
    FileWriter(const string& fileName) {
        file.open(fileName);
    }

    void writeVector(const vector<int>& vec) {
        for (int i = 0; i < vec.size(); ++i) {
            file << vec[i] << ' ';
        }
    }

    ~FileWriter() {
        file.close();
    }

private:
    ofstream file;
};

int main() {
    try {
        FileReader fileReader("input.txt");
        FileWriter fileWriter("output.txt");

        int n = fileReader.read();

        vector<pair<int, int>> pairs;
        fileReader.readPairs(pairs, n);

        vector<int> vec(n);
        for (const auto& pair : pairs) {
            vec[pair.second - 1] = pair.first;
        }

        fileWriter.writeVector(vec);
    }

    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}