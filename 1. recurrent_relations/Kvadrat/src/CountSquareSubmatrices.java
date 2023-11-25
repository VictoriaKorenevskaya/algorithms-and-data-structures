
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class CountSquareSubmatrices {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());

        int[][] matrix = new int[n][m];
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            for (int j = 0; j < m; j++) {
                matrix[i][j] = Integer.parseInt(tokenizer.nextToken());
            }
        }

        reader.close();

        int result = countSquareSubmatrices(matrix);

        writer.write(Integer.toString(result));
        writer.newLine();

        writer.close();
    }

    private static int countSquareSubmatrices(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int[][] dp = new int[n][m];
        int count = 0;

        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }
        for (int j = 1; j < m; j++) {
            dp[0][j] = matrix[0][j];
            count += dp[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    count += dp[i][j];
                }
            }
        }

        return count;
    }
}