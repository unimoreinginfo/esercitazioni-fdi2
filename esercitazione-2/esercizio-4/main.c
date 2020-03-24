/*
#include <stdio.h>
#include <stdlib.h>
*/

int Prodotto(int a, int b) {
	if(a < 0 || b < 0) return -1;
	if(a == 0 || b == 0) return 0;
    if(a == 1) return b;
    if(b == 1) return a;
    return a+Prodotto(a, b-1);
}

/*
int main(int argc, char** argv) {
    if(argc > 2)
        printf("%d\n", Prodotto(atoi(argv[1]), atoi(argv[2])));
    else
        puts("Servono due parametri");
}
*/