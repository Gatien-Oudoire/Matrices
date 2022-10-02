#ifndef MATRICES_H_
#define MATRICES_H_

#include <stdio.h>
#include <stdlib.h>

struct Matrice {
    int lignes; // m i
    int colones; // n j
    // dimension (m, n)

    int ** valeurs;
};

typedef struct Matrice Matrice;

Matrice matrice(int i, int j);
int acceder(Matrice m, int i, int j);
void modifier(Matrice m, int i, int j, int valeur);
void afficher(Matrice m);
Matrice multiplier(Matrice a, Matrice b);

#endif // MATRICES_H_
