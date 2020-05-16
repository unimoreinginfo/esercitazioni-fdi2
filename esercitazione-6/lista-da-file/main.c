#include <stdlib.h>
#include "load.h"
#include "list_int.h"

int main(void) {

	Item *list = LoadList("../data00.txt");
	
	while (list) {

		ElemType e = list->value;

		printf("%d ", e);

		list = list->next;

	}

	return EXIT_SUCCESS;
}