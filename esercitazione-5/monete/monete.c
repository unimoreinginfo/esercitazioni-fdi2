#include <stdlib.h>
#include <stdio.h>
extern int* monete(int* t, int size, int b) {

	// monete già ordinate

	if (b <= 0)
		return NULL;

	int* result = calloc(size, sizeof(int));
	int current_sum = 0;

	for (int i = 0; i < size; i++) {

		while (current_sum + t[i] <= b) {
			result[i] += 1;
			current_sum += t[i];
		}

	}

	return result;

}
