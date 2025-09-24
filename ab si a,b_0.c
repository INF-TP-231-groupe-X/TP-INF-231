#include <stdio.h>

double produit_positif(double a, double b) {
    if (a > 0 && b > 0) {
        return a * b;
    } else {
        printf("Erreur : Les deux nombres doivent être strictement positifs.\n");
        return 0; 
    }
}

int main() {
    double a, b;
    printf("Entrez le premier nombre (strictement positif) : ");
    scanf("%lf", &a);
    printf("Entrez le deuxième nombre (strictement positif) : ");
    scanf("%lf", &b);

    double produit = produit_positif(a, b);
    if (produit > 0) {
        printf("Le produit de %.2f et %.2f est : %.2f\n", a, b, produit);
    }

    return 0;
}