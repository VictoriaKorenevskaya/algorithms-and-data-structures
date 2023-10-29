// unit arrangement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int binomialCoefficient(int n, int k, vector<vector<int>>& dp) {
    if (k == 0 || k == n) {
        return 1;
    }

    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    dp[n][k] = (binomialCoefficient(n - 1, k - 1, dp) + binomialCoefficient(n - 1, k, dp)) % MOD;

    return dp[n][k];
}

int countWays(int n, int k) {

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    return binomialCoefficient(n, k, dp);
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    int result = countWays(n, k);
    cout << result << endl;

    return 0;
}