#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"
#include <stdio.h>

Item* _parse(FILE* file, Item* list);
bool _isValid(Item* list, ElemType* compare);
Item* _parse(FILE* file, Item* list);

Item* Intersect(const Item* i1, const Item* i2) {

	Item* head1 = i1, * head2 = i2;
	Item* intersected = CreateEmptyList();
	Item* intersected_top = intersected;

	Item* longest, * other, * other_top, * longest_top;

	if (ListLength(i1) >= ListLength(i2)) { longest = i1; other = i2; }
	else { longest = i2; other = i1; };

	other_top = other;
	longest_top = longest;

	while (longest) {

		while (other) {

			if (!ElemCompare(&other->value, &longest->value)) 
				// trovato un elemento comune
				intersected = InsertBackList(intersected, &longest->value);

			other = other->next;
		}

		other = other_top;
		longest = longest->next;

	}

	return intersected;

}

int ListLength(Item* i) {
	int n = 0;
	while (!IsEmptyList(i)) {
		n++;
		i = GetTailList(i);
	}
	return n;
}


Item* LoadList(const char* filename) {

	Item* list = CreateEmptyList();
	FILE* file = fopen(filename, "r");
	if (!file)
		return list;

	return _parse(file, list);

}

bool _isValid(Item *list_head, Item* list, int size, ElemType compare) {

	if (!list)
		return true;

	Item* where_to_restart = list;
	list = list_head;

	for(int i = 0; i < size; i++) {

		ElemType e = list->value;

		if (e == compare)
			return false;

		list = list->next;

	}

	list = where_to_restart;

	return true;

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
