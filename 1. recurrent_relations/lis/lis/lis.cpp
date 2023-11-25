

#include <iostream>
#include <fstream>
#include <vector>

int length;
int lisLen = 0;
std::vector<int> arrayA, mas;

int upperBound(int up) {
    int l = 0;
    int r = lisLen;

    while (l < r) {
        int middle = (l + r) / 2;

        if (mas[middle] > up) {
            r = middle;
        }
        else {
            l = middle + 1;
        }
    }

    return l;
}

void lis() {
    for (int i = 0; i < length; i++) {
        int upper = upperBound(arrayA[i]);

        if (upper > 0 && mas[upper - 1] == arrayA[i]) {
            continue;
        }

        if (upper == lisLen) {
            lisLen++;
        }

        mas[upper] = arrayA[i];
    }
}

int main() {
    std::ifstream inFile("input.txt");

    if (!inFile.is_open()) {
        std::cout << "Error with opening input file" << std::endl;
        return 1;
    }

    inFile >> length;
    arrayA.resize(length);
    mas.resize(length, 0);

    for (int i = 0; i < length; i++) {
        inFile >> arrayA[i];
    }

    inFile.close();

    lis();

    std::ofstream outFile("output.txt");

    if (!outFile.is_open()) {
        std::cout << "Error with opening output file " << std::endl;
        return 1;
    }

    outFile << lisLen << std::endl;

    outFile.close();


    return 0;
}