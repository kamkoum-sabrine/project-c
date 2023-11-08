#include <stdio.h>
#include "bib.h"

void ajouterVoiture(VOITURE *v) {
    printf("Donner le code de la voiture ");

    scanf("%d", &v->code);
    printf("Donner le modèle de la voiture ");
    scanf("%s", &v->modele);
    printf("Donner la marque de la voiture ");
    scanf("%s", &v->marque);
    printf("Donner l'année de fabrication de la voiture ");
    scanf("%d", &v->annee);
    printf("Donner le prix de location de la voiture ");
    scanf("%f", &v->prixLocation);
}
void afficherVoiture(VOITURE v){
    printf("Le code de la voiture : %d\n",v.code);
    printf("Le modèle de la voiture: %s\n",v.modele);
    printf("La marque de la voiture: %s\n",v.marque);
    printf("L'année de fabrication de la voiture: %d\n",v.annee);
    printf("Le prix de la voiture: %.2f\n",v.prixLocation);
}

void ajouterClient (CLIENT * c){

    printf("Saisir le CIN du client ");
    scanf("%d", &c->cin);
    printf("Saisir le nom du client ");
    scanf("%s", &c->nom);
    printf("Saisir le prenom du client ");
    scanf("%s", &c->prenom);
    printf("Saisir le telephone du client ");
    scanf("%d", &c->telephone);
    c->nombreLocations=0;
}

void affecterClientToVoiture(CLIENT * c,VOITURE v){
    afficherVoiture(v);
    (*c)->locations[c->nombreLocations]->client=c;
    printf("\n-------------------\n");
    afficherClient(*(c->locations[c->nombreLocations]->client));
    c->locations[c->nombreLocations]->voitureLouee[c->nombreLocations]=v;
    printf("Donner la date debut de location de la voiture pour le client: %s %s ",c->nom, c->prenom);
    scanf("%d",&c->locations[c->nombreLocations]->dateDebut);
    printf("Donner la date fin de location de la voiture ");
    scanf("%d",&c->locations[c->nombreLocations]->dateFin);
    (c->nombreLocations)++;
}

VOITURE rechercherVoitureParCode(int code, VOITURE v[], int nbVoiture){
    ///int trouve =0;
    VOITURE temp;
    temp.code=0;
    int i=0;
    while (i<nbVoiture){
        if (v[i].code==code){
         ///   trouve=1;
            return *v;;
        }
        i++;
    }
    return temp;

}
void remplirTabVoiture (VOITURE *v, int nbVoitures){
    ///VOITURE *stockvoiture;
    int i;
    v=(VOITURE*)malloc(nbVoitures*sizeof(VOITURE));
    for(i=0;i<nbVoitures;i++)
        ajouterVoiture(&v+i);
}
void afficherTabVoiture(VOITURE * v, int nbVoitures){
    int i;
     for(i=0;i<nbVoitures;i++)
        afficherVoiture(v[i]);

}

void afficherClient(CLIENT  c){
    printf("Le CIN du client: %d\n",c.cin);
    printf("Le nom et prénom du client: %s %s\n",c.nom,c.prenom);
    printf("Le telephone du client : %d\n",c.telephone);

}
