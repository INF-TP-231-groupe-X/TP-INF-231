#include <stdio.h>

int recherche_sequentielle(int tableau[], int taille, int cible) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == cible) {
            return i;
        }
    }
    return -1;
}

int main() {
    int tableau[] = {3, 5, 2, 7, 9, 1, 4, 6, 8};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int cible;

    printf("Entrez l'élément à rechercher : ");
    scanf("%d", &cible);

    int indice = recherche_sequentielle(tableau, taille, cible);

    if (indice != -1) {
        printf("L'élément %d est trouvé à l'indice %d.\n", cible, indice);
    } else {
        printf("L'élément %d n'est pas trouvé dans le tableau.\n", cible);
    }

    return 0;
}