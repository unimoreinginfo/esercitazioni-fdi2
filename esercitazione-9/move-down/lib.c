#include <stdlib.h>
#include "minheap_int.h"

void MoveDownMinHeapRec(Heap* h, int i) {

	unsigned int first_idx = 2 * i + 1,
		second_idx = 2 * i + 2,
		smallest_idx;

	if (first_idx > h->size)
		first_idx = -1;
	if (second_idx > h->size)
		second_idx = -1;

	if (first_idx == -1)
		return;
	if (second_idx == -1 && first_idx != -1)
		smallest_idx = first_idx;
	else if (second_idx != -1 && first_idx != -1) {
		if (h->data[first_idx] > h->data[second_idx])
			smallest_idx = second_idx;
		else
			smallest_idx = first_idx;
	}

	ElemSwap(&h->data[i], &h->data[smallest_idx]);
	MoveDownMinHeapRec(h, smallest_idx);

}