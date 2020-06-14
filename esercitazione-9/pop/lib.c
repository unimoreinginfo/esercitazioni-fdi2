#include <stdlib.h>
#include "minheap_int.h"

void heapify(Heap* h);
void lshift(Heap* h);

bool PopMinHeap(Heap* h, ElemType *e) {

	if (!h)
		return false;
	
	if (h->size == 0)
		return false;

	if (!e)
		return false;

	*e = ElemCopy(&h->data[0]);
	h->data[0] = h->data[h->size - 1];
	h->size = h->size - 1;
	heapify(h);

	return true;

}

void heapify(Heap *h) {

	for (int i = (h->size) / 3; i >= 0; i--) {

		MoveDownMinHeap(h, i);

	}

	WriteStdoutHeap(h);

}