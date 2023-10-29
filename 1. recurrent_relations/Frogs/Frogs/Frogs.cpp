// Frogs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int lily;
    int mosquitoes = 0;
    vector<int> mosquitoesOnLily;

    cin >> lily;
    mosquitoesOnLily.resize(lily);

    for (int i = 0; i < lily; ++i) {
        int temp;
        cin >> temp;
        mosquitoesOnLily[i] = temp;
    }

    if (lily == 1) {
        cout << mosquitoesOnLily[0] << endl << "1" << endl;
    }
    else if (lily == 2) {
        cout << -1 << endl;
    }
    else {
        mosquitoesOnLily.push_back(0);
        mosquitoesOnLily[lily - 2] = 0;

        for (int i = lily - 1 - 2; i >= 0; --i) {
            mosquitoesOnLily[i] += maximum(mosquitoesOnLily[i + 2], mosquitoesOnLily[i + 3]);
        }

        mosquitoes = mosquitoesOnLily[0];
        cout << mosquitoes << endl;

        cout << 1;

        for (int i = 0; i < lily - 1;) {
            if (mosquitoesOnLily[i + 2] >= mosquitoesOnLily[i + 3]) {
                i += 2;
            }
            else {
                i += 3;
            }
            cout << " " << i + 1;
        }

        return 0;
    }
}