// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<fstream>

using namespace std;

class Node
{
public:
	Node(long long len)
	{
		Key = new long long[len];
		LeftB = new long long[len];
		RightB = new long long[len];
	}

	~Node()
	{
		delete[] Key;
		delete[] LeftB;
		delete[] RightB;
	}

	bool InsertNewElement(long long x, long long line_n, char side, long long indexOfCurrentNode);

private:

	long long* Key;
	long long* LeftB;
	long long* RightB;
};


bool Node::InsertNewElement(long long x, long long parentPositionNode, char side, long long indexOfCurrentNode)
{
	long long l = LLONG_MIN;
	long long r = LLONG_MAX;

	Key[indexOfCurrentNode] = x;

	if (side == 'L')
	{
		l = LeftB[parentPositionNode - 1];
		r = Key[parentPositionNode - 1];
	}
	else if (side == 'R')
	{
		l = Key[parentPositionNode - 1];
		r = RightB[parentPositionNode - 1];
	}

	if (!(x >= l && x < r))
		return false;

	LeftB[indexOfCurrentNode] = l;
	RightB[indexOfCurrentNode] = r;

	return true;
}


int main()
{
	ifstream inFile;
	inFile.open("bstin.txt");

	long long len;
	inFile >> len;

	Node* tree = new Node(len);
	long long keyVal;
	long long parent;
	char side;

	ofstream outFile;
	outFile.open("bstout.txt");

	inFile >> keyVal;
	tree->InsertNewElement(keyVal, -1, ' ', 0);


	for (long long i = 1; i < len; i++)
	{
		inFile >> keyVal >> parent >> side;
		if (!tree->InsertNewElement(keyVal, parent, side, i))
		{
			outFile << "NO";
			return 0;
		}
	}

	outFile << "YES";

	inFile.close();
	outFile.close();

	return 0;
}