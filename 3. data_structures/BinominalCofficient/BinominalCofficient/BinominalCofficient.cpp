
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class BitExtract {
public:
    static vector<int> extractBits(long long n) {
        vector<int> bits;
        while (n != 0) {
            bits.push_back(n % 2);
            n = n / 2;
        }
        return bits;
    }
};

class Height {
public:
    static void calculateHeight(const vector<int>& bits, ofstream& output) {
        bool hasHeight = false;
        for (int i = 0; i < bits.size(); i++) {
            if (bits[i] == 1) {
                hasHeight = true;
                output << i << "\n";
            }
        }
        if (!hasHeight) {
            output << -1;
        }
    }
};

class ForFiles {
public:
    static bool readFromFile(const string& filename, long long& number) {
        ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        file >> number;
        file.close();
        return true;
    }

    static void writeToFile(const string& filename, const vector<int>& bits) {
        ofstream file(filename);
        Height::calculateHeight(bits, file);
        file.close();
    }
};

int main() {
    long long n;

    if (!ForFiles::readFromFile("input.txt", n)) {
        return 1;
    }

    vector<int> bits = BitExtract::extractBits(n);
    ForFiles::writeToFile("output.txt", bits);

    return 0;
}