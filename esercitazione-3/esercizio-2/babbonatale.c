#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool _isValid(int const*, int, int, int);
unsigned int _weight(bool*, int const*, int);
void _printSolution(bool*, int);

void babboNatale(int p, int const* pacchi, int n, unsigned i, bool* vcurr, bool* vbest, int sum) {

	// nota: vbest = carico con più pacchi possibili

	bool inserted = false;

	if (i == n) {

		if (_weight(vcurr, pacchi, n) > _weight(vbest, pacchi, n))
			memcpy(vbest, vcurr, n);

		return;

	}

	for (int j = i; j < n; j++) {

		if (_isValid(pacchi, j, sum, p)) {
			
			inserted = true;
			vcurr[j] = 1;
			sum += pacchi[j];
			babboNatale(p, pacchi, n, j + 1, vcurr, vbest, sum);

		}

		vcurr[j] = 0;
		if(inserted) sum -= pacchi[j];

	}

	if(i == 0)
		_printSolution(vbest, n);

}

bool _isValid(int const* pacchi, int current_index, int sum, int max_value) {

	if (sum + pacchi[current_index] <= max_value)
		return true;

	return false;

}

unsigned int _weight(bool* arr, int const* weights, int len) {

	unsigned int weight = 0;

	for (int i = 0; i < len; i++) {
		if (arr[i]) {

			weight += weights[i];

		}
	}

	return weight;

}

void _printSolution(bool* arr, int len) {

	for (int i = 0; i < len; i++)
		printf("%d", arr[i]);

	printf("\n");

}