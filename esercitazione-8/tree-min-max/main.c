#include "lib.h"

int main() {

	Node rl1 = { .value = 18, .left = NULL, .right = NULL };
	Node rr1 = { .value = 77, .left = NULL, .right = NULL };

	Node r4 = { .value = 8, .left = NULL, .right = NULL };

	Node r3 = { .value = 2, .left = NULL, .right = NULL };

	Node l2 = { .value = 0, .left = NULL, .right = &r3 };
	Node r2 = { .value = 5, .left = NULL, .right = &r4 };

	Node l1 = { .value = 4, .left = &l2, .right = &r2 };
	Node r1 = { .value = 21, .left = &rl1, .right = &rr1 };


	Node root = { .value = 12, .left = &l1, .right = &r1 };

	printf("%d", BstTreeMax(&root));

}