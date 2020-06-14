#include <stdlib.h>
#include "minheap_int.h"

Heap* HeapifyMinHeap(const ElemType* v, size_t v_size) {

	if (!v)
		return NULL;
	
	if (!v_size)
		return CreateEmptyHeap();

	Heap *new_heap = malloc(sizeof(Heap));
	new_heap->size = v_size;
	new_heap->data = v;

	for (int i = (v_size)/3; i > 0; i--) {

		MoveDownMinHeap(new_heap, i);

	}

	return new_heap;

}