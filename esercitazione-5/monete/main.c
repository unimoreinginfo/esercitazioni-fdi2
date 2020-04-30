#include <stdlib.h>
#include <stdio.h>
#include "monete.h"

int main(void) {

	const int* t[6] = { 50,20,10,5,2,1 };
	const int b = 126;

	int *res = monete(t, 6, b);

	for (int i = 0; i < 6; i++) {

		printf("%d", res[i]);
		printf("\n");

	}

}