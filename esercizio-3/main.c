#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    size_t block_size = 2;

    char c;
    char* str = malloc(block_size);
    int starting_address = str, counter = 0;

    int current_size = 0;

    while ((c = getc(stdin)) != '\n') {

        if (current_size == block_size) {
            block_size *= 2;
            int current_address = str;
            str = starting_address;
            realloc(str, block_size);
            str = current_address;
        }

        *str = c;
        str++;

        current_size++;

    }
    
    *str = '\0';

    str = starting_address;
    printf("%s", str);

}
