/*
#include <stdio.h>
#include <stdlib.h>
*/

unsigned long long Fattoriale(int n) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    return n*Fattoriale(n-1);
}

/*
int main(int argc, char** argv) {
    if(argc > 1)
        printf("%d\n", Fattoriale(atoi(argv[1])));
    else
        puts("Serve un parametro");
}
*/