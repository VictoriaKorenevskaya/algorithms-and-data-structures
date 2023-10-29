import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.IOException;

class BinaryTree {
    static class Node {
        int value;
        Node left, right;

        public Node(int value) {
            this.value = value;
            this.left = this.right = null;
        }
    }

    private Node root;

    public void delete(int value) {
        root = deleteNode(root, value);
    }

    private Node deleteNode(Node root, int value) {
        if (root == null) return null;

        int compare = Integer.compare(value, root.value);

        if (compare > 0) {
            root.right = deleteNode(root.right, value);
        } else if (compare < 0) {
            root.left = deleteNode(root.left, value);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }

            root.value = minValue(root.right);
            root.right = deleteNode(root.right, root.value);
        }

        return root;
    }

    private int minValue(Node root) {
        int minValue = root.value;
        while (root.left != null) {
            minValue = root.left.value;
            root = root.left;
        }
        return minValue;
    }

    public void insert(int value) {
        root = insertNode(root, value);
    }

    private Node insertNode(Node root, int value) {
        if (root == null) {
            return new Node(value);
        }

        int compare = Integer.compare(value, root.value);

        if (compare > 0) {
            root.right = insertNode(root.right, value);
        } else if (compare < 0) {
            root.left = insertNode(root.left, value);
        }

        return root;
    }

    public void preorderTraversal(FileWriter writer) throws IOException {
        preorderTraversal(root, writer);
    }

    private void preorderTraversal(Node root, FileWriter writer) throws IOException {
        if (root == null) return;

        String lineSeparator = System.getProperty("line.separator");
        writer.write(Integer.toString(root.value) + lineSeparator);
        preorderTraversal(root.left, writer);
        preorderTraversal(root.right, writer);
    }
}

public class DeleteFromTree implements Runnable {

    public static void main(String[] args) {
        new Thread(null, new DeleteFromTree(), "", 64 * 1024 * 1024).start();
    }

    public void run() {
        int deletedValue = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            String deletedValueString = reader.readLine();

            if (deletedValueString != null && !deletedValueString.isEmpty()) {
                deletedValue = Integer.parseInt(deletedValueString);
            }

            BinaryTree tree = new BinaryTree();

            String line;
            while ((line = reader.readLine()) != null) {
                if (!line.isEmpty()) {
                    tree.insert(Integer.parseInt(line));
                }
            }

            tree.delete(deletedValue);

            File outputFile = new File("output.txt");

            try (FileWriter writer = new FileWriter(outputFile)) {
                writer.flush();
                tree.preorderTraversal(writer);
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (IOException io) {
            io.printStackTrace();
        }
    }
}