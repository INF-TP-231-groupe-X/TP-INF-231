#include <stdio.h>
#include <stdlib.h>

void produit_vecteur_matrice(double *vecteur, double **matrice, double *resultat, int n, int m) {
    for (int i = 0; i < n; i++) {
        resultat[i] = 0;
        for (int j = 0; j < m; j++) {
            resultat[i] += vecteur[j] * matrice[j][i];
        }
    }
}

void afficher_vecteur(double *vecteur, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%.2f ", vecteur[i]);
    }
    printf("\n");
}

void afficher_matrice(double **matrice, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 3;
    int m = 2;

    double *vecteur = (double *)malloc(m * sizeof(double));
    double **matrice = (double **)malloc(m * sizeof(double *));
    double *resultat = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < m; i++) {
        matrice[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Entrez les éléments du vecteur (%d éléments) :\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%lf", &vecteur[i]);
    }

    printf("Entrez les éléments de la matrice (%dx%d) :\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrice[i][j]);
        }
    }

    produit_vecteur_matrice(vecteur, matrice, resultat, n, m);

    
    printf("Vecteur : ");
    afficher_vecteur(vecteur, m);
    printf("Matrice :\n");
    afficher_matrice(matrice, m, n);
    printf("Résultat : ");
    afficher_vecteur(resultat, n);

    
    free(vecteur);
    for (int i = 0; i < m; i++) {
        free(matrice[i]);
    }
    free(matrice);
    free(resultat);

    return 0;
}