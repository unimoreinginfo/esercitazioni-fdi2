#include <stdlib.h>
#include "diff.h"
#include "list_int.h"

int main(void) {

	Item *list1 = LoadList("../data_01.txt");
	Item *list2 = LoadList("../data_02.txt");

	Item* intersected = Diff(list1, list2);
	
	while (intersected) {

		ElemType e = intersected->value;

		printf("%d ", e);

		intersected = intersected->next;

	}

	return EXIT_SUCCESS;
}