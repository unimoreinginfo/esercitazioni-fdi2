#include "lib.h"

int main() {

	ElemType arr[7] = { 4, 20, 18, 36, 7, 9, 10 };
	Heap* from_arr = HeapifyMinHeap(arr, 7);

	WriteStdoutHeap(from_arr);

}