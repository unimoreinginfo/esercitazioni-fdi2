#include "lib.h"

int main() {

	ElemType arr[7] = { 10, 4, 7, 3, 2, 5, 9 };
	Heap *heap = malloc(sizeof(Heap));
	heap->data = arr;
	heap->size = 7;

	MoveDownMinHeapRec(heap, 0);

}