#ifndef STAZIONIDISERVIZIO_H
#define STAZIONIDISERVIZIO_H

void calcola_stop(int i, double *d, double *p, int n, int dist, int *vcurr, int *vbest, double *best, int *count, double price, double curdist, char *found);
void StazioniServizio(double m, int n, double *d, double *p);

#endif // STAZIONIDISERVIZIO_H
