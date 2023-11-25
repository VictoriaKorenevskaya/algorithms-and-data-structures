

#include <iostream>
#include <fstream>
using namespace std;

class Node {
public:
    int newvalue;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
    bool flag;

    Node(int tr) : newvalue(tr), leftChild(nullptr), rightChild(nullptr), parent(nullptr), flag(false) {}
    Node(int tr, Node* right, Node* left) : newvalue(tr), rightChild(right), leftChild(left), parent(nullptr), flag(false) {}
};

class Tree {
public:
    Node* root;
    int counter;

    Tree() : root(nullptr), counter(0) {}
    Tree(int t) : root(new Node(t)), counter(0) {}

    void addNewRoot(int ad) {
        bool c = false;
        if (root == nullptr) {
            root = new Node(ad);
        }
        else {
            Node* currentNode = root;
            Node* parent = nullptr;
            while (currentNode != nullptr) {
                parent = currentNode;
                if (ad > currentNode->newvalue) {
                    currentNode = currentNode->rightChild;
                }
                else if (ad < currentNode->newvalue) {
                    currentNode = currentNode->leftChild;
                }
                else {
                    c = true;
                    break;
                }
            }
            if (!c) {
                insertNode(parent, ad);
            }
        }
    }

    void LeftCentR() {
        LeftCentR(root);
    }

    void CenterLeftR(ofstream& b) {
        CenterLeftR(root, b);
    }

    void deleteNode(Node* node) {
        if (isLeaf(node)) {
            removeLeaf(node);
        }
        else {
            Node* currentNode = node->rightChild;
            currentNode->parent = node;
            while (currentNode->leftChild != nullptr) {
                currentNode = currentNode->leftChild;
            }
            node->newvalue = currentNode->newvalue;
            replaceNode(currentNode);
        }
    }

    int height() {
        return calculateHeight(root);
    }

    void processTree() {
        height();
        if (counter % 2 != 0) {
            counter /= 2;
            LeftCentR();
        }
    }

private:
    void LeftCentR(Node* node) {
        if (node != nullptr) {
            LeftCentR(node->leftChild);
            if (node->flag == true) {
                if (counter == 0) {
                    deleteNode(node);
                }
                counter--;
            }
            LeftCentR(node->rightChild);
        }
    }

    void CenterLeftR(Node* node, ofstream& x) {
        if (node != nullptr) {
            x << node->newvalue << endl;
            CenterLeftR(node->leftChild, x);
            CenterLeftR(node->rightChild, x);
        }
    }

    void insertNode(Node* parent, int val) {
        Node* newNode = new Node(val);
        if (val < parent-> newvalue) {
            parent -> leftChild = newNode;
            newNode -> parent = parent;
        }
        else {
            parent -> rightChild = newNode;
            newNode -> parent = parent;
        }
    }

    bool isLeaf(Node* node) {
        return node -> rightChild == nullptr && node->leftChild == nullptr;
    }

    void removeLeaf(Node* node) {
        if (node -> parent -> leftChild == node) {
            node -> parent -> leftChild = nullptr;
        }
        else {
            node -> parent -> rightChild = nullptr;
        }
    }

    void replaceNode(Node* node) {
        if (node->parent->leftChild == node) {
            node->parent->leftChild = node->rightChild;
            if (node->rightChild != nullptr)
                node->rightChild->parent = node->parent;
        }
        else {
            node->parent->rightChild = node->rightChild;
            if (node->rightChild != nullptr)
                node->rightChild->parent = node->parent;
        }
    }

    int calculateHeight(Node* h) {
        int h1 = 0;
        int h2 = 0;
        if (h != nullptr) {
            h1 = calculateHeight(h->leftChild);
            h2 = calculateHeight(h->rightChild);
            if (h1 == h2) {
                h->flag = true;
                counter++;
            }
            return max(h1, h2) + 1;
        }
        else
            return -1;
    }
};

int main() {
    ifstream inFile("tstin.txt");
    ofstream outFile("tstout.txt");

    Tree Treeeee;
    int n;

    while (inFile >> n) {
        Treeeee.addNewRoot(n);
    }

    Treeeee.processTree();
    Treeeee.CenterLeftR(outFile);

    outFile.close();

    return 0;
}