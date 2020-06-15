#include "address_book.h"

Item* AppendMod(Item* l1, Item* l2) {

	if (l1 && !l2)
		return l1;

	if (!l1 && l2)
		return l2;

	if (!l1 && !l2)
		return NULL;

	Item* new_list = CreateEmptyList();
	Item* h1 = l1, * h2 = l2;
	Item* head = NULL;
	int is_set = 0;

	while (l1) 
		l1 = l1->next;

	while (l2) {
		l1 = InsertBackList(l1, &l2->value);
		l2 = l2->next;
		l1 = l1->next;
	}

	l1 = h1;
	l2 = h2;

	return h1;

}

Item* Append(const Item* l1, const Item* l2) {

	if (l1 && !l2)
		return l1;

	if (!l1 && l2)
		return l2;

	if (!l1 && !l2)
		return NULL;

	Item* new_list = CreateEmptyList();
	Item* h1 = l1, * h2 = l2;
	Item* head = NULL;
	int is_set = 0;

	while (l1) {
		
		new_list = InsertBackList(new_list, &l1->value);
		if (!is_set) {
			is_set = 0;
			head = new_list;
		}

		l1 = l1->next;

	}

	while (l2) {
		new_list = InsertBackList(new_list, &l2->value);
		l2 = l2->next;
	}
		
	l1 = h1;
	l2 = h2;

	return head;

}

Item* Reverse(Item* l) {

	if (!l)
		return NULL;

	Item* new_list = CreateEmptyList();
	while (l) {

		new_list = InsertHeadList(&l->value, new_list);

		l = l->next;

	}

	return new_list;

}
Item* Filtra(Item* i, const char* city) {

	int is_set = 0, length = 0;
	Item* new_list = NULL, * first_el = NULL;
	Item* h = i;

	while (i) {

		if (!strcmp(i->value.city, city)) {

			if (!is_set) {
				new_list = malloc(sizeof(Item));
				is_set = 1;
				first_el = new_list;
			}			
			new_list->value = ElemCopy(i);
			new_list->next = malloc(sizeof(Item));
				
			new_list = new_list->next;
			length++;

		}

		i = i->next;

	}

	i = h;
	Item* prev_el = NULL;
	new_list = first_el;
	for (int i = 0; i <= length; i++) {
		if (i == length) {
			prev_el->next = NULL;
			break;
		}
		
		prev_el = new_list;
		new_list = new_list->next;
	}

	return first_el;

}

Item* Sort(Item* i) {

	// sort by strcmp (selection sort)
	if (!i)
		return NULL;

	Item* head = i;
	Item* hptr = head;

	while (hptr) {

		Item* min = hptr;
		Item* v = hptr->next;

		// cerco il minimo nella lista "v"
		while (v) {
			if (strcmp(hptr->value.name, v->value.name) > 0)
				min = v;

			v = v->next;

		}

		ElemType t = ElemCopy(&hptr->value);
		hptr->value = min->value;
		min->value = t;
		hptr = hptr->next;

	}

	return head;

}

Item* Delete(Item* i, const char* name) {

	if (!i)
		return NULL;

	Item* head = i,
		*previous_item = NULL;

	while (i) {

		if (!strcmp(name, i->value.name)) {
			
			if (previous_item)
				previous_item->next = i->next;
			else i = i->next;

			return head;

		}

		previous_item = i;
		i = i->next;

	}

	return head;

}

const ElemType* Find(const Item* i, const char* name) {

	if (!i)
		return NULL;

	Item* head = i;

	while (i) {

		if (!strcmp(name, i->value.name)) {
			i = head;
			return &i->value;
		}

		i = i->next;

	}

	i = head;

	return NULL;

}