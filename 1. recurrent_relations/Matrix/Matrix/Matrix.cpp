// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int s;
int* matrixSize;

int minMultiQuantity() {
    int n = s - 1;
    vector<vector<int>> multi(n, vector<int>(n, 0)); 

    for (int length = 1; length < n; length++) {
        for (int i = 0; i < n - length; i++) {
            int j = i + length;
            multi[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int temp1 = multi[i][k] + multi[k + 1][j];
                int temp2 = matrixSize[i] * matrixSize[k + 1] * matrixSize[j + 1];
                int temp = temp1 + temp2;
                if (temp < multi[i][j]) {
                    multi[i][j] = temp;
                }
            }
        }
    }

    return multi[0][n - 1];
}

int main() {
    ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        inputFile >> s;
        s++;

        matrixSize = new int[s];
        inputFile >> matrixSize[0] >> matrixSize[1];

        for (int i = 2; i < s; i++) {
            int temp;
            inputFile >> temp >> matrixSize[i];
        }

        inputFile.close();
    }
    else {
        cout << "Error opening the file" << endl;
        exit(1);
    }


    int result = minMultiQuantity();


    ofstream outputFile("output.txt");

    if (outputFile.is_open()) {
        outputFile << result << endl;
        outputFile.close();
    }
    else {
        cout << "Error writing to the output.txt" << endl;
        exit(1);
    }

    delete[] matrixSize;

    return 0;
}