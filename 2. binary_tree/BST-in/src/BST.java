
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BST implements Runnable {

    public static void main(String[] args) {
        new Thread(null, new BST(), "", 64 * 1024 * 1024).start();
    }

    public void run() {
        try (BufferedReader reader = new BufferedReader(new FileReader("bstin.txt"));
             PrintWriter writer = new PrintWriter("bstout.txt")) {

            int numberOfNodes = Integer.parseInt(reader.readLine());
            Node[] nodes = new Node[numberOfNodes];
            long maximum = 2147483648L;

            int data = Integer.parseInt(reader.readLine());
            nodes[0] = new Node(data, Integer.MIN_VALUE, maximum);

            int value;
            int parentNodeIndex;
            String side;
            boolean result = true;

            for (int i = 1; i < numberOfNodes; ++i) {
                StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
                value = Integer.parseInt(tokenizer.nextToken());
                parentNodeIndex = Integer.parseInt(tokenizer.nextToken());
                side = tokenizer.nextToken();

                if (side.equals("R")) {
                    if (value < nodes[parentNodeIndex - 1].data || value >= nodes[parentNodeIndex - 1].max) {
                        result = false;
                    }
                    nodes[i] = new Node(value, nodes[parentNodeIndex - 1].data, nodes[parentNodeIndex - 1].max);
                } else {
                    if (value >= nodes[parentNodeIndex - 1].data || value < nodes[parentNodeIndex - 1].min) {
                        result = false;
                    }
                    nodes[i] = new Node(value, nodes[parentNodeIndex - 1].min, nodes[parentNodeIndex - 1].data);
                }
            }

            if (result) {
                writer.write("YES");
            } else {
                writer.write("NO");
            }

            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static class Node {
        int data;
        int min;
        long max;

        public Node(int data, int minVal, long maxVal) {
            this.data = data;
            this.min = minVal;
            this.max = maxVal;
        }
    }
}