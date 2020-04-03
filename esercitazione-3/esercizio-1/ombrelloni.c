#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void _printSolution(bool*, int);
bool _isValid(bool*, int, int);
unsigned int _count(bool*, int);


void ombrelloni(int k, int n, unsigned int i, bool* vcurr, unsigned int* nsol) {

	if (i >= n - 1 && _count(vcurr, n) == k) { // ci devono essere almeno k amici perché lo schema sia valido
		*nsol++;
		_printSolution(vcurr, n);
		return;
	}
	
	// mettendo il controllo qui in alto risparmiamo dei cicli

	for (int j = i; j < n; j++) {

		if (_isValid(vcurr, j, n)) { // controlliamo la validità del posto

			if (_count(vcurr, n) < k) // controlliamo che ci siano meno di k elementi, dato che gli amici sono al massimo k
				vcurr[j] = 1; // se è il caso allora inseriamolo

			ombrelloni(k, n, j + 1, vcurr, &nsol); // il passo viene eseguito lo stesso

		}

		vcurr[j] = 0;

	}

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
