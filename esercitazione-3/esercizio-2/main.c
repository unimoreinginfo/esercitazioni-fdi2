#include <stdlib.h>
#include "babbonatale.h"

int main(void) {

	int p = 20;
	int pacchi[5] = { 10, 11, 1, 3, 3 };
	int vcurr[5] = { 0, 0, 0, 0 };
	int vbest[5] = { 0, 0, 0, 0 };

	babboNatale(p, pacchi, 5, 0, vcurr, vbest, 0);

}