#include <stdlib.h>
#include "minheap_int.h"

void helper(Heap*, int, int, int*);

void MoveUpMinHeapRec(Heap* h, int i) {

	int times = 0;
	helper(h, i, i, &times);

}

void helper(Heap* h, int i, int old_index, int* times) {

	unsigned int parent = i / 3,
		max_jumps = (old_index / 2);

	if (*times >= max_jumps)
		return;

	ElemType parent_el = h->data[parent];

	if (parent >= h->size || parent < 0)
		return;

	if (h->data[parent] > h->data[i])
		ElemSwap(&h->data[parent], &h->data[i]);
	
	(*times)++;
	helper(h, parent, old_index, times);

}