#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#include "gioielli.h";

Gioiello* _parse(FILE*);

Gioiello* Gioielli(const char* filename, float b, int* ret_size) {

	FILE* file = fopen(filename, "r");
	if (!file)
		return NULL;

	int total_price, max_price, current_size;
	int max_size = total_price = current_size = 0;
	float current = 0;
	Gioiello* available = _parse(file, &max_size);
	Gioiello* result = malloc(sizeof(Gioiello) * max_size); // per sicurezza allochiamo tutto, poi al max riduco la memoria

	// non devo ordinare

	for (int i = 0; i < max_size; i++) {

		/*
			
			La traccia non mi è troppo chiara (gli esempi non sono troppo esaustivi),
			quindi prendete con le pinze questa soluzione e aspettiamo che torni a funzionare il sito delle consegne 
			per verificare che sia corretta

		*/

		current += available[i].prezzo;

		if (current <= b) {

			result[i] = available[i];
			current_size++;

		}
		else current -= available[i].prezzo;


	}

	realloc(result, current_size * sizeof(Gioiello));
	*ret_size = current_size;

	return result;

}

Gioiello* _parse(FILE* file, int* lines) {

	if (!file)
		return NULL;

	int res, index = 0;
	size_t current_size = sizeof(Gioiello);

	Gioiello* ptr = malloc(current_size);

	while (1) {

		int code;
		float w, p;

		res = fscanf(file, "%d %f %f", &code, &w, &p);

		if (res == EOF)
			break;

		Gioiello g;
		g.codice = code;
		g.peso = w;
		g.prezzo = p;
		
		realloc(ptr, current_size += sizeof(Gioiello));
		ptr[index++] = g;

	}

	*lines = index;
	return ptr;

}