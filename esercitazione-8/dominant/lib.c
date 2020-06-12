#include "lib.h"

void CountDominantRec(const Node*, int*);

int CountDominant(const Node* t) {

	if (!t)
		return 0;

	if (IsLeafTree(t))
		return 0;

	int times = 0;
	CountDominantRec(t, &times);

	return times;

}

void CountDominantRec(const Node* t, int* times) {

	if (IsLeafTree(t))
		return;

	if (!t)
		return;

	Node* left = t->left;
	Node* right = t->right;

	int lvalue, rvalue;

	if (!left) lvalue = 0;
	else lvalue = left->value;

	if (!right) rvalue = 0;
	else rvalue = right->value;

	if (rvalue + lvalue < t->value) (*times)++;

	CountDominantRec(t->left, times);
	CountDominantRec(t->right, times);

}