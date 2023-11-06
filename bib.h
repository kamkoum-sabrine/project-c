#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#include "functions.c"
typedef struct Location LOCATION;
typedef struct Client CLIENT;
typedef struct Voiture VOITURE;

struct Voiture {
    int code;
    char modele[50];
    char marque[50];
    int annee;
    float prixLocation;
    LOCATION * locations[100];
};


struct Location {
    int code;
    VOITURE * voitureLouee;
    CLIENT * client;
    char dateDebut[20];
    char dateFin[20];
};


struct Client {
    int code;
    char nom[50];
    char prenom[50];
    char telephone[15];
    LOCATION * locations[100];
    int nombreLocations;
};

void ajouterVoiture (VOITURE *); ///Une proc�dure qui cr�e une nouvelle voiture
void afficherVoiture (VOITURE); ///Une proc�dure qui affiche les informations d'une voiture

void supprimerVoiture(VOITURE *, int *, int); /**Une proc�dure qui supprime une voiture d'un tableau de
                                            voitures (Elle prend en param�tres le tableau des voitures,
                                             le nombre des voitures dans le tableau et l'indice de voiture � supprimer**/
void miseAJour (VOITURE *,int, int , VOITURE); /**Une proc�dure qui mis � jour une voiture d'un tableau de
                                            voitures (Elle prend en param�tres le tableau des voitures,
                                             le nombre des voitures dans le tableau et l'indice de voiture � mettre � jour
                                             et la nouvelle voiture �dit�e**/
void ajouterClient (CLIENT *); ///Une proc�dure qui cr�e un nouveau client








#endif // BIB_H_INCLUDED
