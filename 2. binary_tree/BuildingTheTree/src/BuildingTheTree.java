import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class BuildingTheTree implements Runnable {

    private static class Tree {

        static class Node {
            Node left, right;
            long key;

            Node(long key) {
                this.key = key;
                this.left = null;
                this.right = null;
            }
        }

        Node head;

        Tree(long key) {
            head = new Node(key);
        }

        void addNode(long key, Node node) {
            if (node == null) {
                node = new Node(key);
            }
            if (key < node.key) {
                if (node.left == null) {
                    node.left = new Node(key);
                } else {
                    addNode(key, node.left);
                }
            }
            if (key > node.key) {
                if (node.right == null) {
                    node.right = new Node(key);
                } else {
                    addNode(key, node.right);
                }
            }
        }

        void leftPreOrdered(Node node, PrintWriter out) {
            if (node != null) {
                out.println(node.key);
                leftPreOrdered(node.left, out);
                leftPreOrdered(node.right, out);
            }
        }
    }

    public static void main(String[] args) {
        new Thread(null, new BuildingTheTree(), "", 64 * 1024 * 1024).start();
    }

    public void run() {
        try (
            BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
            PrintWriter writer = new PrintWriter(new FileWriter("output.txt"))
        ) {
            Tree tree = new Tree(Long.parseLong(reader.readLine()));
            String line;
            while ((line = reader.readLine()) != null) {
                long x = Long.parseLong(line);
                tree.addNode(x, tree.head);
            }

            tree.leftPreOrdered(tree.head, writer);
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}