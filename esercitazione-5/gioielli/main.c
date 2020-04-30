#include <stdlib.h>
#include <stdio.h>

#include "gioielli.h"

int main(void) {

	int size = 0;
	Gioiello *shopping = Gioielli("./gioielli_1.txt", 121, &size);

	for (int i = 0; i < size; i++) {

		printf("Codice: %d, peso: %f, prezzo: %f\n", shopping[i].codice, shopping[i].peso, shopping[i].prezzo);

	}

}