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
    printf("\nAffichage\n");
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
   /// c->locations[c->nombreLocations] = malloc(sizeof(LOCATION));
}

void affecterClientToVoiture(CLIENT * c,VOITURE v){
    c->locations[c->nombreLocations] = (LOCATION*) malloc(sizeof(LOCATION));
   *(c->locations[c->nombreLocations]->voitureLouee)=v;
    printf("Voiture à louer à %s %s\n",c->nom,c->prenom);
    afficherVoiture(*(c->locations[c->nombreLocations]->voitureLouee));
    printf("Donner la date debut de location de la voiture pour le client: %s %s ",c->nom, c->prenom);
    printf("\nJour: ");
    scanf("%d",&c->locations[c->nombreLocations]->dateDebut.jour);
    printf("\nMois: ");
    scanf("%d",&c->locations[c->nombreLocations]->dateDebut.mois);
    printf("\nAnnée: ");
    scanf("%d",&c->locations[c->nombreLocations]->dateDebut.annee);
    printf("Donner la date fin de location de la voiture ");
    printf("\nJour: ");
    scanf("%d",&c->locations[c->nombreLocations]->dateFin.jour);
    printf("\nMois: ");
    scanf("%d",&c->locations[c->nombreLocations]->dateFin.mois);
    printf("\nAnnée: ");
    scanf("%d",&c->locations[c->nombreLocations]->dateFin.annee);

    ///scanf("%d",&c->locations[c->nombreLocations]->dateFin);
    c->nombreLocations++;
}

VOITURE rechercherVoitureParCode(int code, VOITURE v[], int nbVoiture){
    int trouve =0;
    ///VOITURE temp;
    ///temp.code=0;
    int i=0;
    while ((i<nbVoiture)&&(trouve==0)){
        if (v[i].code==code){
            trouve=1;
            return *v;;
        }
        i++;
    }
    if (trouve==0){
        VOITURE voitureParDefaut = { .code = 0 };
        return voitureParDefaut;
    }
 ///   return temp;

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

/**void afficherClient(CLIENT  c){
    int i;
    printf("Le CIN du client: %d\n",c.cin);
    printf("Le nom et prénom du client: %s %s\n",c.nom,c.prenom);
    printf("Le telephone du client : %d\n",c.telephone);
    printf("Les locations : \n");
    for (i=0;i<c.nombreLocations;i++){
        printf("Location num %d\n",i);
        printf("La voiture :\n");
        printf("La bbbbbbbbbbb :\n");
       /// client->locations[i]->voitureLouee
        afficherVoiture(*(c.locations[i]->voitureLouee));
        printf("La date de début de location : %d/%d/%d\n",c.locations[i]->dateDebut.jour,c.locations[i]->dateDebut.mois,c.locations[i]->dateDebut.annee);
        printf("La date de fin de location : %d/%d/%d\n",c.locations[i]->dateFin.jour,c.locations[i]->dateFin.mois,c.locations[i]->dateFin.annee);
    }
}**/


void afficherClient(CLIENT  c) {
    int i;

    printf("Le CIN du client: %d\n", c.cin);
    printf("Le nom et prénom du client: %s %s\n", c.nom, c.prenom);
    printf("Le telephone du client : %d\n", c.telephone);
    printf("Le nombre de ces locations: %d\n",c.nombreLocations);

    /**for (i = 0; i < c.nombreLocations; i++) {
        printf("Location num %d\n", i);

        printf("La voiture :\n");
        printf("9adesh men location %d\n", c.nombreLocations);
        afficherVoiture(*(c.locations[i]->voitureLouee));
        printf("La date de début de location : %d/%d/%d\n",
               c.locations[i]->dateDebut.jour,
               c.locations[i]->dateDebut.mois,
               c.locations[i]->dateDebut.annee);

        printf("La date de fin de location : %d/%d/%d\n",
               c.locations[i]->dateFin.jour,
               c.locations[i]->dateFin.mois,
               c.locations[i]->dateFin.annee);
    }**/
}


/**void afficherTabClients (CLIENT *c, int nbClients){
    ///VOITURE *stockvoiture;
    int i;
    c=(CLIENT*)malloc(nbClients*sizeof(CLIENT));
    for(i=0;i<nbClients;i++)
        afficherClient(&c+i);
}**/
