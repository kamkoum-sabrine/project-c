#include <stdio.h>
#include "bib.h"

void ajouterVoiture(VOITURE *v) {
    printf("Donner le code de la voiture ");

    scanf("%d", &v->code);
    printf("Donner le mod�le de la voiture ");
    scanf("%s", &v->modele);
    printf("Donner la marque de la voiture ");
    scanf("%s", &v->marque);
    printf("Donner l'ann�e de fabrication de la voiture ");
    scanf("%d", &v->annee);
    printf("Donner le prix de location de la voiture ");
    scanf("%f", &v->prixLocation);
}
void afficherVoiture(VOITURE v){
    printf("Le code de la voiture : %d\n",v.code);
    printf("Le mod�le de la voiture: %sn",v.modele);
    printf("La marque de la voiture: %s\n",v.marque);
    printf("L'ann�e de fabrication de la voiture: %d\n",v.annee);
    printf("Le prix de la voiture: %.2f\n",v.prixLocation);
}
/**struct Client {
    int cin;
    char nom[50];
    char prenom[50];
    char telephone[15];
    LOCATION * locations[100];
    int nombreLocations;
};**/
void ajouterClient (CLIENT * c){

    printf("Saisir le CIN du client ");
    scanf("%d", &c->cin);
    printf("Saisir le nom du client ");
    scanf("%s", &c->nom);
    printf("Saisir le prenom du client ");
    scanf("%s", &c->prenom);
    printf("Saisir le telephone du client ");
    scanf("%d", &c->telephone);
}
void afficherClient(CLIENT  c){
    printf("Le CIN du client: %d\n",c.cin);
    printf("Le nom et pr�nom du client: %s %s\n",c.nom,c.prenom);
    printf("Le telephone du client : %d\n",c.telephone);

}