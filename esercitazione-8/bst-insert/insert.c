#include "insert.h"

void BstInsert(const ElemType*, Node*, int*);

Node* BstInsertRec(const ElemType* e, Node* n) {

	if (!n)
		return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());

	Node* top = n;
	int done = 0;

	BstInsert(e, n, &done);

	return top;

}

void BstInsert(const ElemType* e, Node* n, int* done) {

	if (*done)
		return;

	if (*e <= n->value) {

		if (!n->left) { n->left = CreateRootTree(e, NULL, NULL); *done = 1; }
		BstInsert(e, n->left, done);

	}
	else {
		if (!n->right) { n->right = CreateRootTree(e, NULL, NULL); *done = 1; }
		BstInsert(e, n->right, done);
	}

	/*
	// variante non ricorsiva
	while (!done) {

	if (*e <= n->value) {
		if (!n->left) {
			n->left = CreateRootTree(e, NULL, NULL); done = 1;
		}
		n = n->left;
	}
	else {
		if (!n->right) { n->right = CreateRootTree(e, NULL, NULL); done = 1; }
		n = n->right;
	}

}*/

}
