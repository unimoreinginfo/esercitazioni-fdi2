#include <stdlib.h>

typedef struct {

	int codice;
	float peso;
	float prezzo;

} Gioiello;

extern Gioiello* Gioielli(const char* filename, float b, int* ret_size);