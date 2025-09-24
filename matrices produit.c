#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, p;
    printf("Entrez le nombre de lignes de la première matrice (n) : ");
    scanf("%d", &n);
    printf("Entrez le nombre de colonnes de la première matrice (m) : ");
    scanf("%d", &m);
    printf("Entrez le nombre de colonnes de la deuxième matrice (p) : ");
    scanf("%d", &p);

    int **matrice1 = (int **)malloc(n * sizeof(int *));
    int **matrice2 = (int **)malloc(m * sizeof(int *));
    int **produit = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrice1[i] = (int *)malloc(m * sizeof(int));
        produit[i] = (int *)malloc(p * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        matrice2[i] = (int *)malloc(p * sizeof(int));
    }

    printf("Entrez les éléments de la première matrice (%dx%d) :\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Matrice1[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &matrice1[i][j]);
        }
    }

    printf("Entrez les éléments de la deuxième matrice (%dx%d) :\n", m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("Matrice2[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &matrice2[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            produit[i][j] = 0;
            for (int k = 0; k < m; k++) {
                produit[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }

    printf("Première matrice (%dx%d) :\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrice1[i][j]);
        }
        printf("\n");
    }

    printf("Deuxième matrice (%dx%d) :\n", m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", matrice2[i][j]);
        }
        printf("\n");
    }

    printf("Produit des matrices (%dx%d) :\n", n, p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", produit[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(matrice1[i]);
        free(produit[i]);
    }
    for (int i = 0; i < m; i++) {
        free(matrice2[i]);
    }
    free(matrice1);
    free(matrice2);
    free(produit);

    return 0;
}