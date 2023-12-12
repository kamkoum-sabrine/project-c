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
}

void affecterClientToVoiture(CLIENT * c,VOITURE v){
    LOCATION nouvelleLocation;
    DATE dateDeb;
    DATE dateFin;
    nouvelleLocation.voitureLouee = &v;
    printf("\nJour: ");
    scanf("%d",&dateDeb.jour);
    printf("\nMois: ");
    scanf("%d",&dateDeb.mois);
    printf("\nAnnée: ");
    scanf("%d",&dateDeb.annee);
    printf("Donner la date fin de location de la voiture ");
    printf("\nJour: ");
    scanf("%d",&dateFin.jour);
    printf("\nMois: ");
    scanf("%d",&dateFin.mois);
    printf("\nAnnée: ");
    scanf("%d",&dateFin.annee);
    nouvelleLocation.dateDebut = dateDeb;
    nouvelleLocation.dateFin = dateFin;
    printf("DateLocation debut = %d-%d-%d\n",nouvelleLocation.dateDebut.jour,nouvelleLocation.dateDebut.mois, nouvelleLocation.dateDebut.annee );
    c->locations[c->nombreLocations] = &nouvelleLocation;
    printf("DateLocation fin = %d-%d-%d\n",c->locations[c->nombreLocations]->dateFin.jour,c->locations[c->nombreLocations]->dateFin.mois, c->locations[c->nombreLocations]->dateFin.annee );
     printf("\n*****************Code voituree %d\n", c->locations[c->nombreLocations]->voitureLouee->code);
    c->nombreLocations++;


}

VOITURE rechercherVoitureParCode(int code, VOITURE v[], int nbVoiture){
    int trouve =0;

    int i=0;
    while ((i<nbVoiture)&&(trouve==0)){
        if (v[i].code==code){
            trouve=1;
            return v[i];
        }
        i++;
    }
    if (trouve==0){
        VOITURE voitureParDefaut = { .code = 0 };
        return voitureParDefaut;
    }
}
/**void remplirTabVoiture (VOITURE *v, int nbVoitures){
    int i;
    v=(VOITURE*)malloc(nbVoitures*sizeof(VOITURE));
    for(i=0;i<nbVoitures;i++)
        ajouterVoiture(&v+i);
}**/
/**void afficherTabVoiture(VOITURE * v, int nbVoitures){
    int i;
     for(i=0;i<nbVoitures;i++)
        afficherVoiture(v[i]);

}**/

void afficherClient(CLIENT  c) {
    int i;

    printf("Le CIN du client: %d\n", c.cin);
    printf("Le nom et prénom du client: %s %s\n", c.nom, c.prenom);
    printf("Le telephone du client : %d\n", c.telephone);
    printf("Le nombre de ces locations: %d\n",c.nombreLocations);
    VOITURE voiture;
   /**for (i = 0; i < c.nombreLocations; i++) {
        printf("Location num %d\n", i);
        voiture = *(c.locations[i]->voitureLouee);
        printf("Informations sur la voiture louée par le client :\n");
        printf("Code : %d\n", voiture.code);
        printf("Modèle : %s\n", voiture.modele);
        printf("Marque : %s\n", voiture.marque);
        printf("Année : %d\n", voiture.annee);
        printf("Prix de location : %.2f\n", voiture.prixLocation);
        printf("La voiture :");
        printf("%d\n",c.locations[i]->voitureLouee->code);

    }**/
}
void miseAJour(VOITURE *tabVoitures, int nbVoitures, int codeVoiture) {
    int i;
    VOITURE nouvelleVoiture;
    printf("Veuillez entrer le code de la voiture à mettre à jour : ");
    scanf("%d", &(codeVoiture));
    printf("Veuillez entrer les nouvelles informations de la voiture :\n");
    printf("Saisissez le nouveau code de la voiture : ");
    scanf("%d", &nouvelleVoiture.code);

    printf("Saisissez le modèle de la nouvelle voiture : ");
    scanf(" %s", &nouvelleVoiture.modele);

    printf("Saisissez la marque de la nouvelle voiture : ");
    scanf(" %s", &nouvelleVoiture.marque);

    printf("Saisissez l'année de fabrication de la nouvelle voiture : ");
    scanf("%d", &nouvelleVoiture.annee);

    printf("Saisissez le prix de location de la nouvelle voiture : ");
    scanf("%f", &nouvelleVoiture.prixLocation);
    for (i = 0; i < nbVoitures; ++i) {
        if (tabVoitures[i].code == codeVoiture) {
            tabVoitures[i] = nouvelleVoiture;
            int positionAModifier = i; // Position à modifier
            modifierStructure("fichier_structure.dat", positionAModifier, nouvelleVoiture);

         ///   modifierStructure("fichier_structure.dat", positionAModifier, nouvelleVoiture);
            printf("La mise à jour de la voiture avec le code %d a été effectuée avec succès.\n", codeVoiture);
            return;
        }
    }
    printf("Aucune voiture avec le code %d n'a été trouvée. La mise à jour a échoué.\n", codeVoiture);
}
void supprimerVoiture(VOITURE *tabVoitures, int nbVoitures, int codeVoiture) {
    int i,j;
    int voitureTrouvee = 0;

    for (i = 0; i < nbVoitures; ++i) {
        if (tabVoitures[i].code == codeVoiture) {
             for ( j = i; j < (nbVoitures - 1); j++) {
                tabVoitures[j] = tabVoitures[j + 1];
            }

            printf("La voiture avec le code %d a été supprimée avec succès.\n", codeVoiture);
            voitureTrouvee = 1;
            break;
        }
    }

    if (!voitureTrouvee) {
        printf("Aucune voiture avec le code %d n'a été trouvée. La suppression a échoué.\n", codeVoiture);
    }
}

// Fonction pour écrire une structure Voiture dans un fichier structure
void ecrireFichierStructure(const char* nomFichier, VOITURE voiture) {
    FILE* fichier = fopen(nomFichier, "ab"); // Ouverture du fichier en mode ajout binaire

    if (fichier != NULL) {
        fwrite(&voiture, sizeof(VOITURE), 1, fichier); // Écriture de la structure dans le fichier
        fclose(fichier); // Fermeture du fichier
    } else {
        printf("Impossible d'ouvrir le fichier %s\n", nomFichier);
    }
}

// Fonction pour écrire une structure Voiture dans un fichier index
void ecrireFichierIndex(const char* nomFichier, int position) {
    FILE* fichier = fopen(nomFichier, "ab"); // Ouverture du fichier en mode ajout binaire

    if (fichier != NULL) {
        fwrite(&position, sizeof(int), 1, fichier); // Écriture de la position dans le fichier
        fclose(fichier); // Fermeture du fichier
    } else {
        printf("Impossible d'ouvrir le fichier %s\n", nomFichier);
    }
}

// Fonction pour afficher les structures Voiture à partir d'un fichier structure
void afficherFichierStructure(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "rb"); // Ouverture du fichier en mode lecture binaire

    if (fichier != NULL) {
        VOITURE voiture;

        while (fread(&voiture, sizeof(VOITURE), 1, fichier)) {
            printf("Code: %d, Modele: %s, Marque: %s, Annee: %d, Prix de location: %.2f\n",
                   voiture.code, voiture.modele, voiture.marque, voiture.annee, voiture.prixLocation);
        }

        fclose(fichier); // Fermeture du fichier
    } else {
        printf("Impossible d'ouvrir le fichier %s\n", nomFichier);
    }
}

void modifierStructure(const char* nomFichierStructure, int position, VOITURE nouvelleVoiture) {
    FILE* fichierStructure = fopen(nomFichierStructure, "rb+"); // Ouverture du fichier en mode lecture et écriture binaire

    if (fichierStructure != NULL) {
        fseek(fichierStructure, position * sizeof(VOITURE), SEEK_SET); // Déplacement à la position spécifiée

        fwrite(&nouvelleVoiture, sizeof(VOITURE), 1, fichierStructure); // Écriture de la nouvelle structure

        fclose(fichierStructure); // Fermeture du fichier
    } else {
        printf("Impossible d'ouvrir le fichier %s\n", nomFichierStructure);
    }
}

void affichetabclient(CLIENT*c,int nbclients){
    int i;
    for(i=0;i<nbclients;i++){
        printf("\n CLIENT %d",i);
        afficherClient(c[i]);
    }
}

CLIENT* allocationclient(int nbclients){
    CLIENT* tableau;
    tableau=(CLIENT*)malloc(nbclients*sizeof(CLIENT));
    if (!tableau) exit(-1);
    return tableau;
}

VOITURE* allocationvoiture(int nbvoitures ){
    VOITURE* tab;
    tab=(VOITURE*)malloc(nbvoitures*sizeof(VOITURE));
    if (!tab)exit(-1);

    return tab;
}

void afficherTabVoiture(VOITURE * v, int nbVoitures){
    int i;
     for(i=0;i<nbVoitures;i++){
        printf("\nVOITURE %d\n",i);
        ///afficherVoiture(*(stockvoiture+i));
        printf("Contenu du fichier structure :\n");
        afficherFichierStructure("fichier_structure.dat");
     }
}

void remplirTabVoiture (VOITURE *v, int nbVoitures){
    int i;
    for(i=0;i<nbVoitures;i++){
        printf("\nVOITURE %d\n",i);
        // Voiture à écrire dans les fichiers
        ajouterVoiture(v);
        ecrireFichierStructure("fichier_structure.dat", *v);
        ecrireFichierIndex("fichier_index.dat", i); // Stocker la position de la voiture
    }

    /**v=(VOITURE*)malloc(nbVoitures*sizeof(VOITURE));**/
     /**  for(i=0;i<nbVoitures;i++){
           printf("\n VOITURE %d \n ",i);
           ajouterVoiture(&v+i);
       }**/
}

void reallocVoiture(VOITURE *v, int nbVoitures, int nbNouveauxVoitures){

    v = (VOITURE *)realloc(v, (nbVoitures + nbNouveauxVoitures) * sizeof(VOITURE));
    if (v == NULL) {
        printf("Erreur lors du redimensionnement du tableau stockvoiture\n");
    } else {
        nbVoitures += nbNouveauxVoitures;
        int i;
        for (i = nbVoitures - nbNouveauxVoitures; i < nbVoitures; i++) {
            printf("\nVOITURE %d\n", i);
            ajouterVoiture(v + i);

            ecrireFichierStructure("fichier_structure.dat", *(v + i));
            ecrireFichierIndex("fichier_index.dat", i); // Stocker la position de la voiture
        }
    }
}

void remplirTabClient(CLIENT * c, int nbClients, VOITURE *v, int nbVoitures){
            int i;
            int code;
            VOITURE Vloue;
             for(i=0;i<nbClients;i++){

                printf("\nCLIENT %d\n",i);
                ajouterClient(c+i);
                do {

                    printf("Donner le code de voiture a louer pour le client %s %s ",(c+i)->nom, (c+i)->prenom);
                    scanf("%d",&code);

                    Vloue = rechercherVoitureParCode(code,v,nbVoitures);
                if (Vloue.code==0){
                    printf("Voiture introuvable !!\n");
                }
            } while (Vloue.code==0);

            affecterClientToVoiture(c+i,Vloue);
        }
}

void remplirTabResultat (RESULTAT ** tableauResultats,int nbResultats, CLIENT *c, int nbClients,int capaciteResultats){
        int j;
        RESULTAT *nouveauResultat;
        for (j=0; j<nbClients; j++){
            nouveauResultat = (RESULTAT *)malloc(sizeof(RESULTAT));
            if (nouveauResultat == NULL) {
                printf("Erreur lors de l'allocation d'un nouveau résultat\n");
                exit(-2);
            }
            strcpy(nouveauResultat->nomClient, c[j].nom);
            strcpy(nouveauResultat->prenomClient, c[j].prenom);
            nouveauResultat->nbLocations = c[j].nombreLocations;
            int prix=0, v;
            printf("\n****************Nombre locations client %d = %d\n",j,c[j].nombreLocations);
            // Vérifier si le tableau a besoin d'être redimensionné
            if (nbResultats >= capaciteResultats) {
                capaciteResultats *= 2; // Double la capacité du tableau
                tableauResultats = (RESULTAT **)realloc(tableauResultats, capaciteResultats * sizeof(RESULTAT *));
                if (tableauResultats == NULL) {
                    printf("Erreur lors du redimensionnement du tableau de résultats\n");
                    exit(-3);
                }
            }

            // Ajouter l'adresse du nouveau résultat dans le tableau
            tableauResultats[nbResultats] = nouveauResultat;
            nbResultats++; // Augmenter le nombre de résultats
        }
}

void maxNbLocations(RESULTAT** tableauResultats, int nbClients){
    int indexMax = 0;
            int nbMax = tableauResultats[0]->nbLocations;
            printf("\n----------------------\n");
            int i;
            for (i = 1; i < nbClients; i++) {
                if (tableauResultats[i]->nbLocations > nbMax) {
                    nbMax = tableauResultats[i]->nbLocations;
                    indexMax = i;
                }
            }

            // Afficher les détails du client ayant le montant le plus élevé à payer
            printf("Client avec le nombre de location le plus élevé à payer :\n");
            printf("Nom et prénom du client : %s %s\n", tableauResultats[indexMax]->nomClient, tableauResultats[indexMax]->prenomClient);
            printf("Nombre de location : %d\n\n", tableauResultats[indexMax]->nbLocations);
}
