#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void _printSolution(bool*, int);
bool _isValid(bool*, int, int);
unsigned int _count(bool*, int, int);

void ombrelloni(int k, int n, unsigned int i, bool* vcurr, unsigned int* nsol) {

	for (int j = i; j < n; j++) {

		if (_isValid(vcurr, j, n)) { // controlliamo la validità del posto

			vcurr[j] = 1;
			ombrelloni(k, n, j + 1, vcurr, &nsol);

		}

		vcurr[j] = 0;

	}

	if (i >= n - 1 && _count(vcurr, n, 1) == k) { // serve contare che ci siano almeno k amici perché la soluzione sia valida
		*nsol++;
		_printSolution(vcurr, n);
	}
	
	return; // lo sposto qui per correttezza, dentro le parentesi faceva schifo

}

unsigned int _count(bool* vector, int size) {
	
	unsigned int times = 0;

	for (int i = 0; i < size; i++) {

		if (vector[i])
			times++;

	}

	return times;


}

void _printSolution(bool* vector, int size) {

	for (int i = 0; i < size; i++)
		printf("%d", vector[i]);
	
	printf("\n");

}

bool _isValid(bool *vector, int current_index, int n) {

	// uno slot è valido se, nell'array in questione, i posti immediatamente vicini sono azzerati
	
	if (current_index == 0 && !vector[current_index + 1]) return true;

	if (current_index == n - 1 && !vector[current_index - 1]) return true;

	if (vector[current_index + 1] || vector[current_index - 1]) return false;

	return true;

}
