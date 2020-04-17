#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "torredicartoni.h"

void _execTorreCartoni(cartone*, unsigned int, unsigned int, int*, unsigned int);
bool _isValid(cartone*, unsigned int*, unsigned int);

void TorreCartoni(cartone* c, int n) {

    /* Dato un array di n cartoni, la funzione deve individuare la
      configurazione che massimizzi l’altezza di una pila di cartoni,
      rispettando il vincolo che nessun cartone abbia sopra di sé un peso
      superiore al limite consentito.*/

    int* currentBest = malloc(n * sizeof(int)); 
    int* current = malloc(n * sizeof(int));
    unsigned int height = 0;

    currentBest[0] = -180; // non so perché -180, mi andava così

    _execTorreCartoni(c, n, 0, currentBest, current);

    for (unsigned int i = 0; i < n; i++) {

        if (currentBest[i] == -1) // se è -1 vuol dire che l'indice non è valido
            continue;

        printf("\t%d\n", currentBest[i]);
        height += c[currentBest[i]].a;

    }

    printf("Altezza totale: %dcm", height);

}

void _execTorreCartoni(cartone* array, unsigned int len, unsigned int currentStep, int* currentBest, int *current) {


    for (int i = currentStep; i < len; i++) {

        if (_isValid(array, current, i)) {

            current[currentStep] = i;
            _execTorreCartoni(array, len, currentStep + 1, currentBest, current);

        }

        current[currentStep] = -1;

    }

    int totalHeight = 0; // serve per dopo
    int currentBestHeight = 0; // anche questa serve per dopo

    if (currentStep >= len - 1) {

        if (currentBest[0] == -180) {
            // abbiamo trovato la prima soluzione
            for (unsigned int k = 0; k < len; k++) 
                currentBest[k] = current[k];
            
            return;

        }

        for (unsigned int k = 0; k < len; k++) {

            if (current[k] == -1)
                break;

            totalHeight += array[current[k]].a;

        }

        for (unsigned int k = 0; k < len; k++) {

            if (currentBest[k] == -1)
                break;

            currentBestHeight += array[currentBest[k]].a;

        }

        if (totalHeight > currentBestHeight)
            memcpy(currentBest, current, len);

    }

}

bool _isValid(cartone* array, unsigned int* current, int currentStep) {

    /*

        il cartone è impilabile se:
        1) il limite del cartone di sotto è rispettato
        2) il limite del cartone alla base è rispettato

        quindi in sostanza, per il punto 2, se la somma di tutti i pesi sopra al primo cartone + la somma del cartone corrente rispetta il limite del cartone alla base

    */

    if (currentStep == 0)
        return true;

    cartone bottom = array[current[0]];
    unsigned int sum = array[currentStep].p;
    unsigned int weightBefore = array[currentStep - 1].l,
        currentWeight = array[currentStep].p;

    if (weightBefore < currentWeight)
        return false;

    for (unsigned int i = currentStep; i > 1; i--) {

        sum += array[current[i]].p;
        if (sum > bottom.l)
            return false;

    }

    return true;

}