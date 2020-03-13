#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE* file = fopen("./file.txt", "r");

    if (!file)
        return 0;

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

    int read, times = 0;
    char* current_string = malloc(block_size), current_index = 0;

    int starting_current = current_string;

    while ((read = fgetc(file)) != EOF) {
        
        unsigned char actual = (char)read;

        if (actual == ' ' || actual == '\n') {

            current_string[current_index] = 0;

            if (!strcmp(current_string, str))
                counter++;

            memset(current_string, 0, current_index + 1);
            current_index = 0;

        }

        else if (actual != ' ' || actual != '\n') {

            if (current_index == block_size) {
                block_size *= 2;
                int current_address = current_string;
                current_string = starting_current;
                realloc(current_string, block_size);
                current_string = current_address;
            }

            current_string[current_index] = actual;
            current_index++;

        }

    }

    printf("counter: %d", counter);

}
