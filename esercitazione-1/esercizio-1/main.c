#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    if(argc < 4){
        printf("Sono necessari 3 parametri");
        return 0;
    }

    char *s = argv[1];
    char a = *argv[2], b = *argv[3];

    int count_a = 0, count_b = 0;

    for(unsigned int i = 0; i < strlen(s); i++){

        if(s[i] == a)
            count_a++;

        if(s[i] == b)
            count_b++;

    }

    (count_a < count_b) ? printf("Carattere piu' frequente: %c (%d volte)\n", b, count_b) : printf("Carattere piu' frequente: %c (%d volte)\n", a, count_a);

    return 0;

}