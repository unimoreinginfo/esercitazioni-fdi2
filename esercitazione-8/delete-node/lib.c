#include "lib.h"

void helper(Node*, const ElemType*);
Node* max_helper(Node* n, Node* max, int* is_set);
const Node* BstTreeMax(const Node* n);
Node* min_helper(Node* n, Node* max, int* is_set);
const Node* BstTreeMin(const Node* n);

Node* DeleteBstNode(Node* n, const ElemType* key) {

	if (!n)
		return NULL;

	if (!key)
		return n;

	helper(n, key);

	return n;

}

void helper(Node* n, const ElemType* key) {

	if (!n)
		return;

	if (n->value == *key) {

		if (IsLeafTree(n)) {
			DeleteTree(n);
			return;
		}

		if (n->left && n->right) {

			Node* min = BstTreeMin(n->right);
			n->value = ElemCopy(&min->value);
			DeleteTree(min);

		}

		if (n->left && !n->right) {

			Node* max = BstTreeMax(n->left);
			n->value = ElemCopy(max->value);
			DeleteTree(max);

		}

		if (n->right && !n->left) {

			Node* min = BstTreeMin(n->right);
			n->value = ElemCopy(min->value);
			DeleteTree(min);

		}

	}

	if(n->value > *key)
		helper(n->left, key);
	else
		helper(n->right, key);

}

const Node* BstTreeMax(const Node* n) {


	if (!n)
		return NULL;

	Node m;
	int is_set = 0;
	Node* max = max_helper(n, &m, &is_set);

	return max;

}

Node* max_helper(Node* n, Node* max, int* is_set) {

	if (!n)
		return max;

	if (!(*is_set)) {
		max = n;
		*is_set = 1;
	}

	if (n->value > max->value)
		max = n;

	max = max_helper(n->left, max, is_set);
	max = max_helper(n->right, max, is_set);

}

const Node* BstTreeMin(const Node* n) {

	if (!n)
		return NULL;

	Node m;
	int is_set = 0;
	Node* min = min_helper(n, &m, &is_set);

	return min;

}

Node* min_helper(Node* n, Node* min, int* is_set) {

	if (!n)
		return min;

	if (!(*is_set)) {
		min = n;
		*is_set = 1;
	}

	if (n->value < min->value)
		min = n;

	min = min_helper(n->left, min, is_set);
	min = min_helper(n->right, min, is_set);

}