
import java.util.Scanner;

public class CountSquareSubmatrices {
	
	 public static void main(String[] args) {
	        Scanner scanner = new Scanner(System.in);

	        int n = scanner.nextInt();
	        int m = scanner.nextInt();

	        int[][] matrix = new int[n][m];

	        for (int i = 0; i < n; i++) {
	            for (int j = 0; j < m; j++) {
	                matrix[i][j] = scanner.nextInt();
	            }
	        }

	        int result = countSquareSubmatrices(matrix);
	        System.out.println(result);

	        scanner.close();
	    }

    public static int countSquareSubmatrices(int[][] matrix) {
        int count = 0;
        int rows = matrix.length;
        int columns = matrix[0].length;

        int[][] dp = new int[rows][columns];

        for (int i = 0; i < rows; i++) {
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }

        for (int j = 1; j < columns; j++) {
            dp[0][j] = matrix[0][j];
            count += dp[0][j];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                if (matrix[i][j] == 1) {
                    int minValue = Math.min(dp[i - 1][j], dp[i][j - 1]);
                    minValue = Math.min(minValue, dp[i - 1][j - 1]);
                    dp[i][j] = minValue + 1;
                    count += dp[i][j];
                }
            }
        }

        return count;
    }

}


