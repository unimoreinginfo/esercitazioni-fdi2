/*
#include <stdio.h>
#include <stdlib.h>
*/
const int INT_MAX = (1 << 31) - 1; // = 2^31-1 fatto col bit shift

int DivisioneNegativi(int a, int b) {
	if(b == 0) return INT_MAX;
	if(a < 0) return -DivisioneNegativi(-a, b);
    if(b < 0) return -DivisioneNegativi(a, -b);
    if(a < b) return 0;
    return DivisioneNegativi(a-b, b)+1;
}

/*
int main(int argc, char** argv) {
    if(argc > 2)
        printf("%d\n", DivisioneNegativi(atoi(argv[1]), atoi(argv[2])));
    else
        puts("Servono due parametri");
}
*/