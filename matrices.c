#include "matrices.h"
#include <stdio.h>

Matrice matrice(int i, int j) {

  Matrice resultat;
  resultat.lignes = i;
  resultat.colones = j;

  resultat.valeurs = calloc(sizeof(int), i);

  for (int x = 0; x < i; ++x) {
    resultat.valeurs[x] = calloc(sizeof(int), j);
  }

  return resultat;
}

int acceder(Matrice m, int i, int j) { return m.valeurs[i][j]; }

void modifier(Matrice m, int i, int j, int valeur) { m.valeurs[i][j] = valeur; }

void afficher(Matrice m) {
  for (int x = 0; x < m.lignes; ++x) {
    printf("| ");
    for (int z = 0; z < m.colones; ++z)
      printf("%d ", m.valeurs[x][z]);

    printf("|\n");
  }
}

Matrice multiplier(Matrice a, Matrice b) {

  Matrice z = matrice(a.lignes, b.colones);

  for (int i = 0; i < a.lignes; ++i) {

    for (int j = 0; j < b.colones; ++j) {

      // Z_i,j = Σ 1≤k≤n Ai,k*Bk,j
      for (int k = 0; k < b.lignes; k++) {
        // printf("z(j, i) += a(%d, %d) * b(%d, %d) = %d\n", j, k, k, i,
        // a.valeurs[j][k] * b.valeurs[k][i]);
        z.valeurs[i][j] += a.valeurs[i][k] * b.valeurs[k][j];
      }
    }
  }
  return z;
}
