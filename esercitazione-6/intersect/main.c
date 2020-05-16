#include <stdlib.h>
#include "intersect.h"
#include "list_int.h"

int main(void) {

	Item *list1 = LoadList("../data_01.txt");
	Item *list2 = LoadList("../data_02.txt");

	Item* intersected = Intersect(list1, list2);
	
	while (intersected) {

		ElemType e = intersected->value;

		printf("%d ", e);

		intersected = intersected->next;

	}

	return EXIT_SUCCESS;
}