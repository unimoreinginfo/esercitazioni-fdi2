#include "lib.h"

Node* helper(Node*, Node*, int*);

const ElemType* BstTreeMax(const Node* n) {

	// questa implementazione va bene per tutti i tipi di albero, non avevo voglia di scrivere quella del bst
	// in ogni caso, quella del bst è abbastanza simile, basta sfruttarne le proprietà

	if (!n)
		return NULL;

	Node m;
	int is_set = 0;
	Node *max = helper(n, &m, &is_set);

	return max->value;

}

Node* helper(Node* n, Node* max, int* is_set) {

	if (!n)
		return max;

	if (!(*is_set)){
		max = n;
		*is_set = 1;
	}

	if (n->value > max->value)
		max = n;

	max = helper(n->left, max, is_set);
	max = helper(n->right, max, is_set);

}