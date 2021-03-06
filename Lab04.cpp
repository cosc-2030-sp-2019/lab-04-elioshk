// Lab04.cpp
// Eli Oceanak
// COSC 2030 Section 10
// Lab 04

#include "stdafx.h"
#include<iostream>

using namespace std;

struct Node {
	int value;
	struct Node * rightNode = NULL;
	struct Node * leftNode = NULL;
};

Node * searchNode(Node * root, int value) {
	Node * rightResult;
	Node * leftResult;
	if (root == NULL) {
		return NULL;
	}
	else if (root->value == value) {
		return root;
	}
	else {
		rightResult = searchNode(root->rightNode, value);
		leftResult = searchNode(root->leftNode, value);
		if (rightResult == NULL && leftResult == NULL) {
			return NULL;
		}
		else if (rightResult != NULL) {
			return rightResult;
		}
		else {
			return leftResult;
		}
	}
}

void insertLeft(Node * Parent, Node * nodeToInsert) { // Inserts a brand new leftnode to any node in the list
	nodeToInsert->leftNode = Parent->leftNode;
	Parent->leftNode = nodeToInsert;
}


void insertRight(Node * Parent, Node * nodeToInsert) { // Same as above, but w/ a right node
	nodeToInsert->rightNode = Parent->rightNode;
	Parent->rightNode = nodeToInsert;
}


int inOrderTransversal(Node * root) { // Prints values in this order: left, root, right
	if (root != NULL) {
		inOrderTransversal(root->leftNode);
		cout << root->value << endl;
		inOrderTransversal(root->rightNode);
	}
	return 0;
}

int postOrderTransversal(Node * root) { // Prints values in this order: left, right, root
	if (root != NULL) {
		postOrderTransversal(root->leftNode);
		postOrderTransversal(root->rightNode);
		cout << root->value << endl;
	}
	return 0;
}

int preOrderTransversal(Node * root) { // Prints values in this order: Root, left, right
	if (root != NULL) {
		cout << root->value << endl;
		preOrderTransversal(root->leftNode);
		preOrderTransversal(root->rightNode);
	}
	return 0;
}



int main() {
	Node * BinaryTree = new Node; // Creating the order directed for in the picture by inserting nodes
	BinaryTree->value = 5;
	Node * tmp = new Node;
	tmp->value = 1;
	BinaryTree->rightNode = tmp;
	tmp = new Node;
	tmp->value = 4;
	BinaryTree->leftNode = tmp;
	tmp = new Node;
	tmp->value = 10;
	insertLeft(BinaryTree->leftNode, tmp);
	tmp = new Node;
	tmp->value = 15;
	insertRight(BinaryTree->leftNode, tmp);
	tmp = new Node;
	tmp->value = 8;
	insertLeft(BinaryTree->leftNode->rightNode, tmp);
	tmp = new Node;
	tmp->value = 7;
	insertRight(BinaryTree->rightNode, tmp);
	tmp = new Node;
	tmp->value = 9;
	insertRight(BinaryTree->rightNode->rightNode, tmp);
	postOrderTransversal(BinaryTree);
	Node * searchResult = searchNode(BinaryTree, 2);
	if (searchResult != NULL) {
		cout << searchResult << endl;
	}
	else {
		cout << "The node searched does not exist." << endl;
	}
}