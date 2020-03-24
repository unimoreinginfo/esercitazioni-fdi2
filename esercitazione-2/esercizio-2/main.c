/*
#include <stdio.h>
#include <stdlib.h>
*/

int Fibonacci(int n) {
    if(n < 0) return -1;
    if(n == 0 || n == 1) return n;
    if(n > 1) return Fibonacci(n-1)+Fibonacci(n-2);
}

/*
int main(int argc, char** argv) {
    if(argc > 1) {
    	int n = atoi(argv[1]);
    	if(n < 0) {
    		printf("%d\n", Fibonacci(n));
    	} else {
    		printf("Sequenza di Fibonacci fino al %d-esimo elemento:\n", n);
	    	for(int i = 0; i <= n; i++)
	        	printf("%d\n", Fibonacci(i));
	    }
    }
    else
        puts("Serve un parametro");
}
*/