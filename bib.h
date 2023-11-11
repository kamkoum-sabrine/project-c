#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED

typedef struct Location LOCATION;
typedef struct Client CLIENT;
typedef struct Voiture VOITURE;
typedef struct Date DATE;

struct Date {
    int jour;
    int mois;
    int annee;
};


struct Voiture {
    int code;
    char modele[50];
    char marque[50];
    int annee;
    float prixLocation;
    ///LOCATION * locations[100];
};


struct Location {
    ///int code;
    VOITURE * voitureLouee;
    ///CLIENT * client;
    DATE dateDebut;
    DATE dateFin;
};


struct Client {
    int cin;
    char nom[50];
    char prenom[50];
    int telephone[15];
    LOCATION * locations[100];
    int nombreLocations;
};

void ajouterVoiture (VOITURE *); ///Une procédure qui crée une nouvelle voiture
void afficherVoiture (VOITURE); ///Une procédure qui affiche les informations d'une voiture

void supprimerVoiture(VOITURE *, int *, int); /**Une procédure qui supprime une voiture d'un tableau de
                                            voitures (Elle prend en paramètres le tableau des voitures,
                                             le nombre des voitures dans le tableau et l'indice de voiture à supprimer**/
void miseAJour (VOITURE *,int, int , VOITURE); /**Une procédure qui mis à jour une voiture d'un tableau de
                                            voitures (Elle prend en paramètres le tableau des voitures,
                                             le nombre des voitures dans le tableau et l'indice de voiture à mettre à jour
                                             et la nouvelle voiture éditée**/
void ajouterClient (CLIENT *); ///Une procédure qui crée un nouveau client
void afficherClient (CLIENT ); ///Une procédure qui affiche les informations d'une voiture
void affecterClientToVoiture(CLIENT *, VOITURE);
VOITURE rechercherVoitureParCode(int, VOITURE [], int);
void remplirTabVoiture(VOITURE * , int nbVoitures);
void afficherTabVoiture(VOITURE* , int nbVoitures);
void remplirTabClient(CLIENT * , int nbClients);
void afficherTabClients(CLIENT *, int);







#endif // BIB_H_INCLUDED
