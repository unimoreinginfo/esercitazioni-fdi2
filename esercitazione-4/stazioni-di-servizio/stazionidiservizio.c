#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CONSUMO 0.05
#define CAPIENZA 30

const int KM_LITRO = 1/CONSUMO;
const int KM_SERBATOIO = 30*KM_LITRO;


void calcola_stop(int i, double *d, double *p, int n, int dist, int *vcurr, int *vbest, double *best, int *count, double price, double curdist, char *found) {
    if(curdist >= dist && price < *best) {
        memcpy(vbest, vcurr, n*sizeof(int));
        *best = price;
        *count = i;
        *found = 1;
    }
    if(i == n) return;
    for(int j = 0; j < n; j++) {
        if(d[j] > curdist-KM_SERBATOIO && curdist >= d[j])  {
            vcurr[i] = j;
            double prev_stop = curdist - KM_SERBATOIO;
            double distance_from_last_stop = d[j] - prev_stop;
            double cost = distance_from_last_stop*CONSUMO*p[j];

            calcola_stop(i+1, d, p, n, dist, vcurr, vbest, best, count, price+cost, d[j]+KM_SERBATOIO, found);
        }
    }
}

void StazioniServizio(double m, int n, double *d, double *p) {
    /* Nota per i cari colleghi studenti.
     * Inizialmente avevo capito male la traccia (come accade spesso).
     * Pensavo che d fosse un vettore del tipo: la prima stazione
     * al kilometro d[0], la seconda al kilometro d[1]... dal punto
     * di partenza, ma poi mi sono accorto che mi sbagliavo, quindi invece
     * di cambiare la soluzione ho adattato l'input per fare in
     * modo che fosse come pensavo io, ecco perché c'è newd e questo for.
     */
    double *newd = malloc(n*sizeof(double));
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum+=d[i];
        newd[i] = sum;
    }
    int *vcurr = calloc(n, sizeof(int));
    int *vbest = calloc(n, sizeof(int));
    double best = 100000000;
    int k = 0;
    char found = 0;
    calcola_stop(0, newd, p, n, m, vcurr, vbest, &best, &k, 0, 30/0.05, &found);
    if(!found) {
        printf("Non esistono soluzioni\n");
        return;
    }
    for(int i = 0; i < k; i++) {
        printf("%d ", vbest[i]);
    }
    printf("\nSpesa totale: %lf euro\n", best);
    free(vcurr);free(vbest);free(newd);
}
