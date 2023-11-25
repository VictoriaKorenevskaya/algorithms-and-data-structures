
import java.io.*;
import java.util.*;

public class BinaryHeapChecker {
    static boolean isBinaryHeap(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int leftChildIndex = 2 * i + 1;
            int rightChildIndex = 2 * i + 2;

            if (isValidIndex(leftChildIndex, arr.length) && arr[leftChildIndex] < arr[i]) {
                return false;
            }

            if (isValidIndex(rightChildIndex, arr.length) && arr[rightChildIndex] < arr[i]) {
                return false;
            }
        }
        return true;
    }

    static boolean isValidIndex(int index, int length) {
        return index >= 0 && index < length;
    }

    public static void main(String[] args) {
        try {
            File inFile = new File("input.txt");
            Scanner scanner = new Scanner(inFile);

            int arrSize = scanner.nextInt();
            int[] inputArray = new int[arrSize];

            for (int i = 0; i < arrSize; i++) {
                inputArray[i] = scanner.nextInt();
            }

            FileWriter outFile = new FileWriter("output.txt");
            if (isBinaryHeap(inputArray)) {
                outFile.write("Yes");
            } else {
                outFile.write("No");
            }

            scanner.close();
            outFile.flush();
            outFile.close();
        } catch (Exception e) {
            System.out.println("An error occurred: " + e);
            System.exit(1);
        }
    }
}