#include <stdlib.h>
#include <stdbool.h>
#include "ombrelloni.h"

int main() {

	int k = 2, n = 5, nsol = 0;
	bool v[5] = { 0, 0, 0, 0, 0 };

	ombrelloni(k, n, 0, v, &nsol);

	return 0;

}