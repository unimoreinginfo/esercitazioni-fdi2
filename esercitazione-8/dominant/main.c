#include "lib.h"

int main() {

	Node rl1 = { .value = 5, .left = NULL, .right = NULL };
	Node rr1 = { .value = 7, .left = NULL, .right = NULL };

	Node l2 = { .value = 3, .left = NULL, .right = NULL };
	Node r2 = { .value = 21, .left = NULL, .right = NULL };

	Node l1 = { .value = 5, .left = &l2, .right = &r2 };
	Node r1 = { .value = 13, .left = &rl1, .right = &rr1 };

	Node root = { .value = 10, .left = &l1, .right = &r1 };

	CountDominant(&root);
	
	printf("ciao");

}