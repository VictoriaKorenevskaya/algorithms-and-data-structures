import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Huffman {

    private static long travers1 = 0, travers2 = 0, puVal = 0;
    private static long n;
    private static long[][] A;
    private static long res = 0, result = 0;

    private static void readInputs() throws FileNotFoundException {
        try (Scanner scanner = new Scanner(new File("huffmanin.txt"))) {
            n = scanner.nextLong();
            A = new long[2][];
            A[0] = new long[(int) (n + 10)];
            A[1] = new long[(int) (n + 10)];
            for (int i = 0; i < n; i++) {
                A[0][i] = scanner.nextLong();
            }
        }
    }

    private static void writeOutputs() throws FileNotFoundException {
        try (PrintWriter writer = new PrintWriter("huffmanout.txt")) {
            writer.println(res - result);
        }
    }

    private static void totalHuffman() {
        while (travers1 < n || A[1][(int) travers2] != 0) {
            long temp = 0;

            if (travers1 >= n || (A[1][(int) travers2] != 0 && A[0][(int) travers1] >= A[1][(int) travers2])) {
                temp = A[1][(int) travers2++];
            } else {
                temp = A[0][(int) travers1++];
            }

            if (travers1 < n && (A[1][(int) travers2] == 0 || A[0][(int) travers1] < A[1][(int) travers2])) {
                temp += A[0][(int) travers1++];
            } else {
                temp += A[1][(int) travers2++];
            }

            res += temp;
            result = temp;
            A[1][(int) puVal++] = temp;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        readInputs();
        totalHuffman();
        writeOutputs();
    }
}