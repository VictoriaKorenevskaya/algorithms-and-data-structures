
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<vector<int>, vector<int>> longestCommonSubsequence(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }

    int k = n;
    int i = n;
    vector<int> indices_A;
    vector<int> indices_B;
    while (i > 0 && k > 0) {
        if (A[i - 1] == B[k - 1]) {
            indices_A.push_back(i - 1);
            indices_B.push_back(k - 1);
            i--;
            k--;
        }
        else if (f[i - 1][k] >= f[i][k - 1]) {
            i--;
        }
        else {
            k--;
        }
    }

    reverse(indices_A.begin(), indices_A.end());
    reverse(indices_B.begin(), indices_B.end());

    return make_pair(indices_A, indices_B);
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        cin >> B[i];

    pair<vector<int>, vector<int>> result = longestCommonSubsequence(A, B);

    vector<int> indices_A = result.first;
    vector<int> indices_B = result.second;

    cout << indices_A.size() << "\n";

    for (int i = 0; i < indices_A.size(); i++)
        cout << indices_A[i] << " ";

    cout << "\n";

    for (int i = 0; i < indices_B.size(); i++)
        cout << indices_B[i] << " ";

    cout << "\n";

    return 0;
}