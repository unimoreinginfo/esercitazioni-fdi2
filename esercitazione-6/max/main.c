#include <stdlib.h>
#include "max.h"
#include "list_int.h"

int main(void) {

	Item *list1 = LoadList("../data_01.txt");

	ElemType max = MaxElement(list1);
	
	printf("%d", max);

	return EXIT_SUCCESS;
}