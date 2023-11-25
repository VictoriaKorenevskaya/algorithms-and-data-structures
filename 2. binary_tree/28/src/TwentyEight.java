import java.io.*;

public class TwentyEight implements Runnable {
	public static void main(String[] args) {
		new Thread(null, new TwentyEight(), "", 64 * 1024 * 1024).start();
	}

	public void run() {
		try (BufferedReader reader = new BufferedReader(new FileReader("tstin.txt"))) {
			PrintWriter writer = new PrintWriter("tstout.txt");
			String string;
			Tree firstTree = new Tree();

			while ((string = reader.readLine()) != null) {
				int x = Integer.parseInt(string);
				firstTree.addNewNode(x);
			}

			firstTree.high(firstTree.root);
			if (firstTree.counter % 2 != 0) {
				firstTree.counter /= 2;
				firstTree.LCenterRTraversal();
			}
			firstTree.CLeftRightTraversal(writer);
			writer.flush();
			writer.close();
		} catch (NumberFormatException e) {

		} catch (IOException e) {

		}
	}

}

class Node {
	int valueInTheNode;
	Node leftChild;
	Node rightChild;
	Node parent;
	boolean isSuitable;

	public Node(int va) {
		this.valueInTheNode = va;
		this.leftChild = this.rightChild = null;
		isSuitable = false;
	}

	public Node(int va, Node right, Node left) {
		this.valueInTheNode = va;
		this.rightChild = right;
		this.leftChild = left;
		isSuitable = false;
	}
}

class Tree {
	Node root;
	int counter;

	public Tree() {
		root = null;
		counter = 0;
	}

	public Tree(int t) {
		this.root = new Node(t);
		counter = 0;
	}

	public void addNewNode(int value) {
		boolean n = false;
		if (root == null) {
			root = new Node(value);
		} else {
			Node t = root;
			Node parent = null;
			while (t != null) {
				parent = t;
				if (value > t.valueInTheNode) {
					t = t.rightChild;
				} else if (value < t.valueInTheNode) {
					t = t.leftChild;
				} else {
					n = true;
					break;
				}
			}
			if (n == false) {
				if (value < parent.valueInTheNode) {
					t = new Node(value);
					parent.leftChild = t;
					t.parent = parent;
				} else {
					t = new Node(value);
					parent.rightChild = t;
					t.parent = parent;
				}
			}
		}
	}

	public void LCenterRTraversal() {
		LCenterRTraversal(this.root);
	}

	private void LCenterRTraversal(Node node) {
		if (node != null) {

			LCenterRTraversal(node.leftChild);
			if (node.isSuitable == true) {
				if (counter == 0) {
					delete(node);
				}
				counter--;
			}
			LCenterRTraversal(node.rightChild);
		}
	}

	public void CLeftRightTraversal(PrintWriter b) {
		CLeftRightTraversal(this.root, b);
	}

	private void CLeftRightTraversal(Node node, PrintWriter b) {
		if (node != null) {
			b.println(node.valueInTheNode);
			CLeftRightTraversal(node.leftChild, b);
			CLeftRightTraversal(node.rightChild, b);
		}
	}

	public void delete(Node node) {
		if ((node.rightChild == null) && (node.leftChild == null)) {
			if (node.parent.leftChild == node)
				node.parent.leftChild = null;
			else if (node.parent.rightChild == node)
				node.parent.rightChild = null;
		} else {

			Node t = node.rightChild;
			t.parent = node;
			while (t.leftChild != null) {
				t = t.leftChild;
			}
			node.valueInTheNode = t.valueInTheNode;
			if (t.parent.leftChild == t) {
				t.parent.leftChild = t.rightChild;
				if (t.rightChild != null)
					t.rightChild.parent = t.parent;
			} else {
				t.parent.rightChild = t.rightChild;
				if (t.rightChild != null)
					t.rightChild.parent = t.parent;
			}
		}
	}

	public int high(Node h) {
		int highh = 0;
		int highhhh = 0;
		if (h != null) {
			highh = high(h.leftChild);
			highhhh = high(h.rightChild);
			if (highh == highhhh) {
				h.isSuitable = true;
				counter++;
			}
			return Integer.max(highh, highhhh) + 1;
		} else
			return -1;
	}
}