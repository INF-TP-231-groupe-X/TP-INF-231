#include <stdio.h>

int est_trie(int tableau[], int taille) {
    int sens = 0;

    for (int i = 0; i < taille - 1; i++) {
        if (tableau[i] < tableau[i + 1]) {
            if (sens == 0) {
                sens = 1;
            } else if (sens == -1){
                return 0; 
            }
        } else if (tableau[i] > tableau[i + 1]) {
            if (sens == 0) {
                sens = -1;
            } else if (sens == 1) {
                return 0;
            }
        }
    }

    return 1; 
}

int main() {
    int tableau[] = {1, 2, 3, 4, 5};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    if (est_trie(tableau, taille)) {
        printf("Le tableau est trié.\n");
    } else {
        printf("Le tableau n'est pas trié.\n");
    }

    return 0;
}