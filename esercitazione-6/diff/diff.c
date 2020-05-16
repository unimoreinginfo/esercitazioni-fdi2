#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"
#include <stdio.h>
#include <stdbool.h>

Item* _parse(FILE* file, Item* list);

Item* Diff(const Item* i1, const Item* i2) {

	Item* diff = NULL;
	Item* head1 = i1, * head2 = i2, * diff_top = malloc(sizeof(Item));
	int size = 0;

	// attezione: questa funzione fa schifo

	while (i1) {

		if (!i2)
			break;

		Item* current_item = i1;
		bool found = false;

		while (i2) {

			if (current_item->value == i2->value) {
				found = true;
				break;
			}

			i2 = i2->next;

		}

		if (!found) {

			Item* t = calloc(sizeof(Item)); // l'ultimo item aggiunto è sempre NULL
			if (!diff)
				diff = diff_top;

			diff->value = i1->value;
			diff->next = t;
			diff = diff->next;
			size++;

		}

		i1 = i1->next;
		i2 = head2;

	}

	diff = diff_top;

	for (int i = 0; i < size; i++) {
		if (i == size - 1)
			diff->next = NULL;

		diff = diff->next;
	}

	diff = diff_top;
	i1 = head1;
	i2 = head2;

	return diff;

}

Item* LoadList(const char* filename) {

	Item* list = CreateEmptyList();
	FILE* file = fopen(filename, "r");
	if (!file)
		return list;

	return _parse(file, list);

}

Item* _parse(FILE* file, Item* list) {

	while (1) {

		int current;
		int res = fscanf(file, "%d", &current);

		if (res == EOF)
			break;

		ElemType r = current;

		list = InsertBackList(list, &r);

	}

	return list;

}