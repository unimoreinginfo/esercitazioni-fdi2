#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void _printSolution(bool*, int);
bool _isValid(bool*, int);
unsigned int _count(bool*, int);


void ombrelloni(int k, int n, unsigned int i, bool* vcurr, unsigned int* nsol) {
	
	if (k == _count(vcurr, n)) {
		
		// il caso limite è quando dentro alla fila ci sono già due amici
		// ci fermiamo qua
		
		_printSolution(vcurr, n);
		return;

	}

	if (i == n)
		return;

	if (_isValid(vcurr, i)) {

		if (_count(vcurr, n) < k) {

			vcurr[i] = 1;
			ombrelloni(k, n, i + 1, vcurr, nsol);
			vcurr[i] = 0;

		}

	}
	
	ombrelloni(k, n, i + 1, vcurr, nsol);

}

void _printSolution(bool* vector, int size) {

	for (int i = 0; i < size; i++)
		printf("%d ", vector[i]);

	printf("\n");

}

unsigned int _count(bool* vector, int size) {

	unsigned int n = 0;

	for (int i = 0; i < size; i++) {

		if (vector[i])
			n++;

	}

	return n;

}

bool _isValid(bool* vector, int index) {

	if (index == 0)
		return true;

	if (!vector[index - 1])
		return true;

	return false;

}
