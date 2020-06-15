#pragma once
#define mamma_mia malloc(sizeof(Item));
#include <stdlib.h>
#include <string.h>
#include "list_int.h"

const ElemType* Find(const Item* i, const char* name);
Item* Delete(Item* i, const char* name);
Item* Sort(Item* i);
Item* Filtra(Item* i, const char* city);
Item* Reverse(Item* l);
Item* Append(const Item* l1, const Item* l2);
Item* AppendMod(Item* l1, Item* l2);