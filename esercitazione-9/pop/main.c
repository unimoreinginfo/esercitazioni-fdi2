#include <stdlib.h>
#include "minheap_int.h"
#include "lib.h"

int main() {

	ElemType arr[6];
	Heap* heap = malloc(sizeof(Heap));
	heap->data = malloc(sizeof(int) * 6);
	heap->data = arr;
	heap->size = 6;
	ElemType result;

	PopMinHeap(heap, &result);

}