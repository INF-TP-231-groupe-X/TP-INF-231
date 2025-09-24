#include <stdio.h>

void inverser_tableau(int tableau[], int taille) {
    int temp;
    for (int i = 0; i < taille / 2; i++) {
        temp = tableau[i];
        tableau[i] = tableau[taille - i - 1];
        tableau[taille - i - 1] = temp;
    }
}

void afficher_tableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

int main() {
    int tableau[] = {1, 2, 3, 4, 5};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau original : ");
    afficher_tableau(tableau, taille);

    inverser_tableau(tableau, taille);

    printf("Tableau inversé : ");
    afficher_tableau(tableau, taille);

    return 0;
}