
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main()
{
    ifstream inFile;
    inFile.open("input.txt");

    vector<char> str(7000);

    int lenght = 0;
    while (inFile >> str[lenght])
        lenght++;

    inFile.close();

    vector<vector<int>> F(lenght, vector<int>(lenght));

    for (int i = 0; i < lenght - 1; i++)
    {
        F[i][i] = 1;

        if (str[i] == str[i + 1])
            F[i][i + 1] = 2;
        else
            F[i][i + 1] = 1;
    }
    F[lenght - 1][lenght - 1] = 1;

    int jj;
    for (int j = 2; j < lenght; j++)
    {
        for (int i = 0; i < lenght - j; i++)
        {
            jj = i + j;
            if (str[i] == str[jj])
                F[i][jj] = F[i + 1][jj - 1] + 2;
            else
                F[i][jj] = max(F[i + 1][jj], F[i][jj - 1]);
        }
    }

    char* result = new char[F[0][lenght - 1]];

    int i = 0;
    int j = lenght - 1;
    int k = 0;

    while (i <= j)
    {
        if (str[i] == str[j])
        {
            result[k] = str[i];
            result[F[0][lenght - 1] - k - 1] = str[i];
            k++;
            i++;
            j--;
        }
        else
        {
            if (F[i][j] == F[i][j - 1])
                j--;
            else if (F[i][j] == F[i + 1][j])
                i++;
        }
    }

    ofstream outFile;
    outFile.open("output.txt");

    outFile << F[0][lenght - 1] << "\n";

    for (i = 0; i < F[0][lenght - 1]; i++)
        outFile << result[i];

    outFile.close();

    return 0;
}