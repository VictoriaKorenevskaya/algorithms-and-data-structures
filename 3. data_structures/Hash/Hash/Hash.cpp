
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class HashTable {
public:
    HashTable(int size, int c) : table(size, -1), c(c) {}

    void insert(int key) {
        int i = 0;
        while (true) {
            int attempt = ((key % table.size()) + c * i) % table.size();
            if (table[attempt] == key || table[attempt] == -1) {
                table[attempt] = key;
                break;
            }
            i++;
        }
    }

    void printToFile(const string& filename) const {
        ofstream outFile(filename);

        for (int i : table)
            outFile << i << " ";

        outFile << std::flush;
        outFile.close();
    }

private:
    vector<int> table;
    int c;
};

int main() {
    try {
        ifstream inFile("input.txt");

        int tableSize, c, keys;
        inFile >> tableSize >> c >> keys;

        HashTable hashTable(tableSize, c);

        for (int i = 0; i < keys; i++) {
            int key;
            inFile >> key;
            hashTable.insert(key);
        }

        inFile.close();

        hashTable.printToFile("output.txt");
    }

    catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        exit(1);
    }
    catch (...) {
        cerr << "Unknown exception caught." << endl;
        exit(1);
    }

    return 0;
}