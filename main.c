#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "main.h"
#include "utils.h"

node *initTree(int value) {
	node *tree = malloc(sizeof(node));
	assert(tree != NULL);

	tree->value = value;
	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;

	return tree;
}

node *search(node *tree, int value) {
	if (tree->value == value) return tree;

	if (tree->left != NULL) {
		node *resultLeft = search(tree->left, value);
		if (resultLeft != NULL) return resultLeft;
	}

	if (tree->right != NULL) {
		node *resultRight = search(tree->right, value);
		if (resultRight != NULL) return resultRight;

	}
	return NULL;
}

bool insert(node *tree, bool side, int value, int parent) {
	// Side: left if 0 else right;
	node *parentNode = search(tree, parent);
	node *newNode = initTree(value);
	assert(newNode != NULL);

	if (side == 0) { // Case 1: left
		assert(parentNode->left == NULL);

		parentNode->left = newNode;
		newNode->parent = parentNode;

		return true;
	} else {
		assert(parentNode->right == NULL);

		parentNode->right = newNode;
		newNode->parent = parentNode;

		return true;
	}
}

bool removeLeaf(node *tree, int value) {
	node *leaf = search(tree, value);
	node *parent = leaf->parent;

	// Verify if it exists;
	if (leaf == NULL) return false;
	// Verify if leaf is a leaf;
	if (leaf->left != NULL || leaf->right != NULL) return false;

	if (parent->left == leaf) {
		// Case 1: remove left child
		parent->left = NULL;
		leaf->parent = NULL;
		free(leaf);

		return true;
	} else if (parent->right == leaf) {
		// Case 2: remove right child
		parent->right = NULL;
		leaf->parent = NULL;
		free(leaf);

		return true;
	}

	return false;
}

void prefixe(node *tree) {
	// Format: value, left, right;
	if (tree == NULL) return;
	printf("%d ", tree->value);
	prefixe(tree->left);
	prefixe(tree->right);
	return;
}

void infixe(node *tree) {
	// Format: left, value, right;
	if (tree == NULL) return;

	infixe(tree->left);
	printf("%d ", tree->value);
	infixe(tree->right);
	return;
}

void postfixe(node *tree) {
	// Format: left, right, value;
	if (tree == NULL) return;

	postfixe(tree->left);
	postfixe(tree->right);
	printf("%d ", tree->value);
}

int depth(node *tree) {
	int left = 0;
	int right = 0;
	if (tree == NULL) return -1;

	left = depth(tree->left);
	right = depth(tree->right);

	return max(left, right) + 1;
}

int size(node *tree) {
	int left = 0;
	int right = 0;
	if (tree == NULL) return 0;

	left = size(tree->left);
	right = size(tree->right);

	return left + right + 1;
}

// TODO: list to tree
int main() {
	node *tree1 = initTree(1);
	return 0;
}

