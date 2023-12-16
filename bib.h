#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED

typedef struct Location LOCATION;
typedef struct Client CLIENT;
typedef struct Voiture VOITURE;
typedef struct Date DATE;
typedef struct Resultat RESULTAT;

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
};


struct Location {
    int code;
    VOITURE * voitureLouee;
    DATE dateDebut;
    DATE dateFin;
};


struct Client {
    int cin;
    char nom[50];
    char prenom[50];
    int telephone;
    LOCATION * locations[100];
    int nombreLocations;
};

struct Resultat {
    char nomClient[50];
    char prenomClient[50];
    int nbLocations;
};

void ajouterVoiture (VOITURE *); ///Créer une nouvelle voiture
void afficherVoiture (VOITURE); ///Afficher les informations d'une voiture
void ajouterClient (CLIENT *,VOITURE *,int ); ///Créer un nouveau client
void afficherClient (CLIENT ); ///Afficher les informations d'une voiture
void affecterClientToVoiture(CLIENT *, VOITURE);///affecter une voiture donnée à un client précis
VOITURE rechercherVoitureParCode(int, VOITURE [], int);///Chercher une voiture par son code et la retourner
void miseAJour (VOITURE *,int, int ); ///mettre à jour une voiture
void supprimerVoiture(VOITURE *, int  , int); ///supprimer une voiture
void afficherTabVoiture(VOITURE * , int );///Afficher le tableau des voitures
void affichetabclient(CLIENT*,int);///Afficher le tableau des clients
CLIENT* allocationclient(int); ///Allouer le tableau client et retourner l'adresse du 1ere case
VOITURE* allocationvoiture(int );///allocation du tableau voiture et retourner l'adresse du 1ere case
void remplirTabVoiture (VOITURE *, int);///Remplir le tableau voiture
void reallocVoiture(VOITURE *, int, int);///redimentionner le tableau voiture
void remplirTabClient (CLIENT *, int, VOITURE *, int);///Remplir le tableau client
void remplirTabResultat (RESULTAT **,int , CLIENT *, int, int);///Remplir le tableau resultats
void maxNbLocations(RESULTAT**, int );///Rechercher et afficher le client qui a  le plus grand nb de locations
void creerFichierClientsIndex(FILE**,FILE**);
void remplirFichierClientsIndex(FILE*,FILE*,VOITURE*,int,CLIENT *,int);
void afficherFichierClientsIndex(FILE*,FILE*,int);
void ecrireUnClientDansFichier(FILE*, CLIENT);
CLIENT lireUnClientDuFichier(FILE*);
#endif // BIB_H_INCLUDED
