/*
#include <stdio.h>
#include <stdlib.h>
*/

int ProdottoNegativi(int a, int b) {
	if(a < 0) return -ProdottoNegativi(-a, b);
	if(b < 0) return -ProdottoNegativi(a, -b);
	if(a == 0 || b == 0) return 0;
    if(a == 1) return b;
    if(b == 1) return a;
    return a+ProdottoNegativi(a, b-1);
}

/*
int main(int argc, char** argv) {
    if(argc > 2)
        printf("%d\n", ProdottoNegativi(atoi(argv[1]), atoi(argv[2])));
    else
        puts("Servono due parametri");
}
*/