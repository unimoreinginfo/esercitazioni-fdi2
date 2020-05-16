#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"
#include <stdio.h>

Item* _parse(FILE* file, Item* list);
bool _isValid(Item* list, ElemType* compare);

ElemType MaxElement(const Item* i) {

	const Item* head = i;
	ElemType max = head->value;
	head = head->next;

	while (head) {

		if (max < head->value)
			max = head->value;

		head = head->next;

	}

	i = head;

	return max;

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
	fclose(file);
	return list;

}
