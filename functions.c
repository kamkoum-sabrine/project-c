#include <stdio.h>
#include "bib.h"

void ajouterVoiture(VOITURE *v) {
    printf("Donner le code de la voiture ");
    scanf("%d", &v->code);
    printf("Donner le mod�le de la voiture ");
    scanf("%s", v->modele);
    printf("Donner la marque de la voiture ");
    scanf("%s", v->marque);
    printf("Donner l'ann�e de fabrication de la voiture ");
    scanf("%d", &v->annee);
    printf("Donner le prix de location de la voiture ");
    scanf("%f", &v->prixLocation);
}
