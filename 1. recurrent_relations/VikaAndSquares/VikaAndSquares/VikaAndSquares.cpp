// VikaAndSquares.cpp : This file contains the 'main' function. Program execution begins and ends there.

//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int countSquareSubmatrices(vector<vector<int>>& matrix) {
//    int count = 0;
//    int rows = matrix.size();
//    int columns = matrix[0].size();
//
//    vector<vector<int>> dp(rows, vector<int>(columns, 0));
//
//    for (int i = 0; i < rows; i++) {
//        dp[i][0] = matrix[i][0];
//        count += dp[i][0];
//    }
//
//    for (int j = 1; j < columns; j++) {
//        dp[0][j] = matrix[0][j];
//        count += dp[0][j];
//    }
//
//    for (int i = 1; i < rows; i++) {
//        for (int j = 1; j < columns; j++) {
//            if (matrix[i][j] == 1) {
//                int minValue = min(dp[i - 1][j], dp[i][j - 1]);
//                minValue = min(minValue, dp[i - 1][j - 1]);
//                dp[i][j] = minValue + 1;
//                count += dp[i][j];
//            }
//        }
//    }
//
//    return count;
//}
//
//int main() {
//    int n, m;
//   scanf_s("%d", &n);
//   scanf_s("%d", &m);
//
//    vector<vector<int>> matrix(n, vector<int>(m));
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> matrix[i][j];
//        }
//    }
//  
//    int result = countSquareSubmatrices(matrix);
//    printf_s("%d", result);
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int countSquareSubmatrices(int** matrix, int rows, int columns) {
//    int count = 0;
//
//    int** dp = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        dp[i] = new int[columns];
//        fill(dp[i], dp[i] + columns, 0);
//    }
//
//    for (int i = 0; i < rows; i++) {
//        dp[i][0] = matrix[i][0];
//        count += dp[i][0];
//    }
//
//    for (int j = 1; j < columns; j++) {
//        dp[0][j] = matrix[0][j];
//        count += dp[0][j];
//    }
//
//    for (int i = 1; i < rows; i++) {
//        for (int j = 1; j < columns; j++) {
//            if (matrix[i][j] == 1) {
//                int minValue = min(dp[i - 1][j], dp[i][j - 1]);
//                minValue = min(minValue, dp[i - 1][j - 1]);
//                dp[i][j] = minValue + 1;
//                count += dp[i][j];
//            }
//        }
//    }
//
//    for (int i = 0; i < rows; i++) {
//        delete[] dp[i];
//    }
//    delete[] dp;
//
//    return count;
//}
//
//int main() {
//    int n, m;
//    scanf_s("%d", &n);
//    scanf_s("%d", &m);
//
//    int** matrix = new int* [n];
//    for (int i = 0; i < n; i++) {
//        matrix[i] = new int[m];
//    }
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> matrix[i][j];
//        }
//    }
//
//    int result = countSquareSubmatrices(matrix, n, m);
//    printf_s("%d", result);
//
//    for (int i = 0; i < n; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int countSquareSubmatrices(vector<vector<int>>& matrix) {
//    int count = 0;
//    int rows = matrix.size();
//    int columns = matrix[0].size();
//
//    vector<vector<int>> dp(rows, vector<int>(columns, 0));
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {
//            if (matrix[i][j] == 1) {  
//                if (i == 0 || j == 0) {
//                    dp[i][j] = 1;
//                }
//                else { 
//                    dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
//                }      
//                count += dp[i][j];
//            }
//        }
//    }
//
//    return count;
//}
//
//int main() {
//    int n, m;
//    scanf_s("%d", &n);
//    scanf_s("%d", &m);
//
//    vector<vector<int>> matrix(n, vector<int>(m));
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> matrix[i][j];
//        }
//    }
//
//    int result = countSquareSubmatrices(matrix);
//    printf_s("%d", result);
//    return 0;
//}