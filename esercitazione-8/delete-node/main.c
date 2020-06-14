#include "lib.h"

int main() {

	Node* rl1 = malloc(sizeof(Node));  rl1->value = 18; rl1->left = NULL; rl1->right = NULL;
	Node* rr1 = malloc(sizeof(Node)); rr1->value = 77;  rr1->left = NULL; rr1->right = NULL;
	Node* r4 = malloc(sizeof(Node)); r4->value = 8; r4->left = NULL; r4->right = NULL;
	Node* r3 = malloc(sizeof(Node)); r3->value = 2; r3->left = NULL; r3->right = NULL;
	Node* l2 = malloc(sizeof(Node)); l2->value = 0; l2->left = NULL; l2->right = r3;
	Node* r2 = malloc(sizeof(Node)); r2->value = 5; r2->left = NULL; r2->right = r4;
	Node* l1 = malloc(sizeof(Node)); l1->value = 4; l1->left = l2; l1->right = r2;
	Node* r1 = malloc(sizeof(Node)); r1->value = 21; r1->left = rl1; r1->right = rr1;
	Node* root = malloc(sizeof(Node)); root->value = 12; root->left = l1; root->right = r1;

	ElemType key = 21;

	DeleteBstNode(root, &key);

}