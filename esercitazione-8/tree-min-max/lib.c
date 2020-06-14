#include "lib.h"

Node* helper(Node*, Node*, int*);
Node* min_helper(Node*, Node*, int*);

const ElemType *BstTreeMin(const Node* n){

	// questa implementazione va bene per tutti i tipi di albero, non avevo voglia di scrivere quella del bst
	// in ogni caso, quella del bst � abbastanza simile, basta sfruttarne le propriet�

	if (!n)
		return NULL;

	Node m;
	int is_set = 0;
	Node *min = min_helper(n, &m, &is_set);

	return min->value;

}

const ElemType* BstTreeMax(const Node* n) {

	// questa implementazione va bene per tutti i tipi di albero, non avevo voglia di scrivere quella del bst
	// in ogni caso, quella del bst � abbastanza simile, basta sfruttarne le propriet�

	if (!n)
		return NULL;

	Node m;
	int is_set = 0;
	Node *max = helper(n, &m, &is_set);

	return max->value;

}

Node* min_helper(Node* n, Node* min, int* is_set) {

	if (!n)
		return min;

	if (!(*is_set)){
		min = n;
		*is_set = 1;
	}

	if (n->value < max->value)
		min = n;

	min = helper(n->left, min, is_set);
	min = helper(n->right, min, is_set);

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