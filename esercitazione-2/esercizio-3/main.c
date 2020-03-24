/*
#include <stdio.h>
#include <stdlib.h>
*/

int Minimo(int *vec, int len) {
    if(len == 1) return *vec;
    if(vec[0] > vec[len-1])
        return Minimo(vec+1, len-1);
    return Minimo(vec, len-1);
}

/*
int main(int argc, char **argv) {
    if(argc == 1)
        puts("Servono dei parametri di cui calcolare il minimo");
    else {
        int *arr = malloc(argc-1);
        for(int i = 1; i < argc; i++) {
            arr[i-1] = atoi(argv[i]);
        }
        printf("%d\n", Minimo(arr, argc-1));
    }	
}
*/