#include <stdio.h>
#include <stdlib.h>

void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partitionner(int tableau[], int debut, int fin) {
    int pivot = tableau[fin];
    int i = debut - 1;

    for (int j = debut; j < fin; j++) {
        if (tableau[j] < pivot) {
            i++;
            echanger(&tableau[i], &tableau[j]);
        }
    }

    echanger(&tableau[i + 1], &tableau[fin]);
    return i + 1;
}


void quicksort(int tableau[], int debut, int fin) {
    if (debut < fin) {
        int pivot = partitionner(tableau, debut, fin);
        quicksort(tableau, debut, pivot - 1);
        quicksort(tableau, pivot + 1, fin);
    }
}


double trouver_median(int tableau[], int taille) {
    quicksort(tableau, 0, taille - 1);

    if (taille % 2 == 0) {
        return (tableau[taille / 2 - 1] + tableau[taille / 2]) / 2.0;
    } else {
        return tableau[taille / 2];
    }
}

int main() {
    int tableau[] = {12, 4, 56, 7, 8, 34, 23, 9, 11};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    double median = trouver_median(tableau, taille);
    printf("Le médian est : %.2f\n", median);

    return 0;
}