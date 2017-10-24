#include "BTree.h"



BTree::BTree() {
	root = NULL;
	leaves = 0;
}

BTree::BTree(int d) {
	Leaf *leaf = new Leaf(d);
	root = leaf;
	leaves = 1;
}

BTree::~BTree() {}

void BTree::insert(int d, Leaf *root) {
	if (!isEmpty()) {
		if (d < root->getData()) {
			if (!root->left) {
				root->left = new Leaf(d);
				leaves++;
			}
			else {
				insert(d, root->left);
			}
		}
		else {
			if (!root->right) {
				root->right = new Leaf(d);
				leaves++;
			}
			else {
				insert(d, root->right);
			}
		}
	}
	else {
		root = new Leaf(d);
		leaves = 1;
	}
}

void BTree::showLeaf(Leaf *root) {
	root->print();
}

int BTree::Height(Leaf *root) {
	if (isEmpty()) {
		return 0;
	}
	else {
		int a, b;
		if (!root->left && !root->right) {
			return 1;
		}
		else {
			a = Height(root->left);
			b = Height(root->right);
			if (a > b) return a + 1;
			else return b + 1;
		}
	}
}

int BTree::getLeaves() {
	return leaves;
}

bool BTree::isEmpty() {
	return leaves == 0;
}

Leaf BTree::getRoot() {
	if (isEmpty()) {
		return NULL;
	}
	else {
		return root->getData();
	}
}
