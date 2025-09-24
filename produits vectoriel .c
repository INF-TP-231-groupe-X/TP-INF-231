#include <stdio.h>

typedef struct {
    double x, y, z;
} Vecteur3D;


Vecteur3D produit_vectoriel(Vecteur3D v1, Vecteur3D v2) {
    Vecteur3D resultat;
    resultat.x = v1.y * v2.z - v1.z * v2.y;
    resultat.y = v1.z * v2.x - v1.x * v2.z;
    resultat.z = v1.x * v2.y - v1.y * v2.x;
    return resultat;
}


void afficher_vecteur(Vecteur3D v) {
    printf("(%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}

int main() {
    Vecteur3D v1 = {1, 2, 3};
    Vecteur3D v2 = {4, 5, 6};

    printf("Vecteur 1 : ");
    afficher_vecteur(v1);
    printf("Vecteur 2 : ");
    afficher_vecteur(v2);

    Vecteur3D produit = produit_vectoriel(v1, v2);
    printf("Produit vectoriel : ");
    afficher_vecteur(produit);

    return 0;
}