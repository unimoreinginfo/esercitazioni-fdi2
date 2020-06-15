#include "address_book.h"
#include <stdlib.h>

int main() {

	Item* book = mamma_mia;
	Item* second = mamma_mia;
	Item* third = mamma_mia;
	Item* fourth = mamma_mia;

	ElemType address1 = { .name = "Birbolotto", .street = "Vingle Vangle", .number = 18, .city = "Bologna", .province = "BO", .postal_code = "40019" };
	ElemType address2 = { .name = "Fonglerio", .street = "Come va vez", .number = 128, .city = "Bologna", .province = "BO", .postal_code = "40019" };
	ElemType address3 = { .name = "Rongle", .street = "Vanglerissima", .number = 148, .city = "Ferrara", .province = "FE", .postal_code = "12356" };
	ElemType address4 = { .name = "Jim", .street = "Olio Carli", .number = 618, .city = "Giacarta", .province = "GI", .postal_code = "12312" };
	book->value = address1;
	book->next = second;

	second->value = address2;
	second->next = third;

	third->value = address3;
	third->next = fourth;

	fourth->value = address4;
	fourth->next = NULL;

	ElemType *find = Find(book, "Fonglerio");
	Delete(book, "Fonglerio");
	Sort(book);
	Item *filtered = Filtra(book, "Bologna");
	Item* reversed = Reverse(book);
	Item* appended = Append(book, book);
	Item* bapp = AppendMod(book, book);


}
