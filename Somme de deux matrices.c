#include <stdio.h>
#include <stdlib.h>

void creer_matrice(int **matrice, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Entrez l'élément [%d][%d] : ", i + 1, j + 1);
            scanf("%d", &matrice[i][j]);
        }
    }
}

void afficher_matrice(int **matrice, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void somme_matrices(int **matrice1, int **matrice2, int **somme, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            somme[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
}

int main() {
    int n, m;
    printf("Entrez le nombre de lignes (n) : ");
    scanf("%d", &n);
    printf("Entrez le nombre de colonnes (m) : ");
    scanf("%d", &m);

    
    int **matrice1 = (int **)malloc(n * sizeof(int *));
    int **matrice2 = (int **)malloc(n * sizeof(int *));
    int **somme = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrice1[i] = (int *)malloc(m * sizeof(int));
        matrice2[i] = (int *)malloc(m * sizeof(int));
        somme[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Entrez les éléments de la première matrice :\n");
    creer_matrice(matrice1, n, m);
    printf("Entrez les éléments de la deuxième matrice :\n");
    creer_matrice(matrice2, n, m);

    somme_matrices(matrice1, matrice2, somme, n, m);
    
    printf("La première matrice est :\n");
    afficher_matrice(matrice1, n, m);
    printf("La deuxième matrice est :\n");
    afficher_matrice(matrice2, n, m);
    printf("La somme des matrices est :\n");
    afficher_matrice(somme, n, m);

    for (int i = 0; i < n; i++) {
        free(matrice1[i]);
        free(matrice2[i]);
        free(somme[i]);
    }
    free(matrice1);
    free(matrice2);
    free(somme);

    return 0;
}