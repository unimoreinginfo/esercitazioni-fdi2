#pragma once

typedef struct {
    unsigned p;  // peso
    unsigned a;  // altezza
    unsigned l;  // limite
} cartone;

void TorreCartoni(cartone* c, int n);