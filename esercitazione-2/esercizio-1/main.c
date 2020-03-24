/*
#include <stdio.h>
#include <stdlib.h>
*/

int Somma(int n) {
    if(n < 1) return -1;
    if(n == 1) return 1;
    if(n > 1) return n+Somma(n-1);
}

/*
int main(int argc, char** argv) {
    if(argc > 1)
        printf("%d\n", Somma(atoi(argv[1])));
    else
        puts("Serve un parametro");
}
*/