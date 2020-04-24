#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool _isValid(int const*, int, int, int);
unsigned int _count(bool*, int);
void _printSolution(bool*, int);

void babboNatale(int p, int const* pacchi, int n, unsigned i, bool* vcurr, bool* vbest, int sum) {

	// nota: vbest = carico con più pacchi possibili, con peso totale inferiore a p

	if (i == n) {

		if (_count(vcurr, n) > _count(vbest, n))
			memcpy(vbest, vcurr, sizeof(int) * n);

		return;

	}

	bool inserted = false;

	if (_isValid(pacchi, i, sum, p)) {

		vcurr[i] = 1;
		inserted = true;
		sum += pacchi[i];

		babboNatale(p, pacchi, n, i + 1, vcurr, vbest, sum);

		vcurr[i] = 0;

	}

	if (inserted)
		sum -= pacchi[i];

	if(i != n - 1) babboNatale(p, pacchi, n, i + 1, vcurr, vbest, sum);

	if (i == 0)
		_printSolution(vbest, n);

}

bool _isValid(int const* pacchi, int current_index, int sum, int max_value) {

	if (sum + pacchi[current_index] <= max_value)
		return true;

	return false;

}

unsigned int _count(bool* arr, int len) {

	unsigned int count = 0;

	for (int i = 0; i < len; i++) {
		if (arr[i]) {

			count++;

		}
	}

	return count;

}

void _printSolution(bool* arr, int len) {

	for (int i = 0; i < len; i++)
		printf("%d", arr[i]);

	printf("\n");

}
