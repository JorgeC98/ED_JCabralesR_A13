#pragma once
#include "Leaf.cpp"

class BTree
{

private:
	Leaf *root;
	int leaves;

public:
	BTree();
	BTree(int d);
	~BTree();

	void insert(int d, Leaf *root);
	void showLeaf(Leaf *root);
	void deleteLeaf(int d);
	bool isEmpty();
	Leaf getRoot();
	int Height(Leaf *root);
	int getLeaves();
};

