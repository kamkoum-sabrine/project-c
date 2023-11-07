#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
int main()
{

    VOITURE v1;
    ajouterVoiture(&v1);
    afficherVoiture(v1);
    /**VOITURE v1;
    printf("Donner le code de la voiture ");
    scanf("%d", &v1.code);
    printf("Donner le modèle de la voiture ");
    scanf("%s", &v1.modele);
    printf("Donner la marque de la voiture ");
    scanf("%s",  &v1.marque);
    printf("Donner l'année de fabrication de la voiture ");
    scanf("%d",  &v1.annee);
    printf("Donner le prix de location de la voiture ");
    scanf("%f", &v1.prixLocation);**/
    return 0;
}
