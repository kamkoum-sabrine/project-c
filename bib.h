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
    int telephone;
    LOCATION * locations[100];
    int nombreLocations;
};

struct Resultat {
    char nomClient[50];
    char prenomClient[50];
    int nbLocations;
};
void ajouterVoiture (VOITURE *); ///Une procédure qui crée une nouvelle voiture
void afficherVoiture (VOITURE); ///Une procédure qui affiche les informations d'une voiture
void ajouterClient (CLIENT *); ///Une procédure qui crée un nouveau client
void afficherClient (CLIENT ); ///Une procédure qui affiche les informations d'une voiture
void affecterClientToVoiture(CLIENT *, VOITURE);
VOITURE rechercherVoitureParCode(int, VOITURE [], int);
void miseAJour (VOITURE *,int, int , VOITURE);
void supprimerVoiture(VOITURE *, int  , int);
void ecrireFichierStructure(const char*, VOITURE);
void ecrireFichierIndex(const char* , int );
void afficherFichierStructure(const char* );
void modifierStructure(const char* , int , VOITURE);


#endif // BIB_H_INCLUDED
