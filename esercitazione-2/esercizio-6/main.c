/*
#include <stdio.h>
#include <stdlib.h>
*/

int Divisione(int a, int b) {
    if(a < b) return 0;
    if(a < 0 || b <= 0) return -1;
    return Divisione(a-b, b)+1;
}

/*
int main(int argc, char** argv) {
    if(argc > 2)
        printf("%d\n", Divisione(atoi(argv[1]), atoi(argv[2])));
    else
        puts("Servono due parametri");
}
*/