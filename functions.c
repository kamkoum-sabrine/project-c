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

void ajouterClient (CLIENT * c,VOITURE *v,int nbVoitures){

    printf("Saisir le CIN du client ");
    scanf("%d", &c->cin);
    printf("Saisir le nom du client ");
    scanf("%s", &c->nom);
    printf("Saisir le prenom du client ");
    scanf("%s", &c->prenom);
    printf("Saisir le telephone du client ");
    scanf("%d", &c->telephone);
    printf("Saisir le nombre de locations de ce client ");
    scanf("%d", &c->nombreLocations);
    louerVoiture(c,v,nbVoitures);
   /// c->nombreLocations=0;
}

void louerVoiture(CLIENT * c, VOITURE *v, int nbVoitures){
    int i,code;
    LOCATION nouvelleLocation;
    DATE dateDeb;
    DATE dateFin;
    VOITURE Vloue;
    for (i=0;i<c->nombreLocations;i++){
        printf("\nLOCATION %d\n",i+1);
        do {

            printf("Donner le code de voiture a louer pour le client %s %s ",(c+i)->nom, (c+i)->prenom);
            scanf("%d",&code);

            Vloue = rechercherVoitureParCode(code,v,nbVoitures);
        if (Vloue.code==0){
            printf("Voiture introuvable !!\n");
        }
        } while (Vloue.code==0);

    ///affecterClientToVoiture(c+i,Vloue);
        nouvelleLocation.voitureLouee = &Vloue;
        printf("Le code de location ");
        int j;
        unsigned long long nombreAleatoire = 0;
        for (j = 0; j < 9; ++j) {
            nombreAleatoire = nombreAleatoire * 10ULL + (rand() % 10);
        }

        printf("%llu\n",nombreAleatoire);
        nouvelleLocation.code=nombreAleatoire;
        ///scanf("%d",&nouvelleLocation.code);
        printf("Donner la date debut de location de la voiture ");
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
       /// c->nombreLocations++;
    }



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

void afficherClient(CLIENT  c) {
    int i;

    printf("Le CIN du client: %d\n", c.cin);
    printf("Le nom et prénom du client: %s %s\n", c.nom, c.prenom);
    printf("Le telephone du client : %d\n", c.telephone);
    printf("Le nombre de ces locations: %d\n",c.nombreLocations);
    printf("Codes locations\n");
    for(i=0;i<c.nombreLocations;i++){
        printf("%d\t",c.locations[i]->code);
    }
    printf("\n");
    VOITURE voiture;
   for (i = 0; i < c.nombreLocations; i++) {
        printf("Location num %d\n", i);
        printf("Code location: %d\n",c.locations[i]->code);
        /**printf("Date debut location: %d/%d/%d\n",c.locations[i]->dateDebut.jour,c.locations[i]->dateDebut.mois,c.locations[i]->dateDebut.annee);
        voiture = *(c.locations[i]->voitureLouee);
        printf("Informations sur la voiture louée par le client :\n");
        printf("Code : %d\n", voiture.code);
        printf("Modèle : %s\n", voiture.modele);
        printf("Marque : %s\n", voiture.marque);
        printf("Année : %d\n", voiture.annee);
        printf("Prix de location : %.2f\n", voiture.prixLocation);
        printf("La voiture :");
        printf("%d\n",c.locations[i]->voitureLouee->code);**/

    }
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
        if ((tabVoitures+i)->code == codeVoiture) {
            *(tabVoitures+i) = nouvelleVoiture;
            int positionAModifier = i; // Position à modifier

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

    afficherTabVoiture(tabVoitures, nbVoitures);
    for (i = 0; i < nbVoitures; i++) {
        printf("\nCompteur %d\n",i);
        printf("(tabVoitures+i)->code = %d\n",(tabVoitures+i)->code);
        printf("codeVoiture = %d\n",codeVoiture);
        if ((tabVoitures+i)->code == codeVoiture) {
             for ( j = i; j < (nbVoitures - 1); j++) {
                *(tabVoitures+j) = *(tabVoitures+j+ 1);
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

void affichetabclient(CLIENT*c,int nbclients){
    int i;
    for(i=0;i<nbclients;i++){
        printf("\n CLIENT %d",i+1);
        afficherClient(*(c+i));
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
        afficherVoiture(*(v+i));
     }
}

void remplirTabVoiture (VOITURE *v, int nbVoitures){
    int i;
    for(i=0;i<nbVoitures;i++){
        printf("\nVOITURE %d\n",i+1);
        ajouterVoiture(v+i);
    }
}

void reallocVoiture(VOITURE *v, int nbVoitures, int nbNouveauxVoitures){

    ///Redimentionner le tableau voitures v
    v = (VOITURE *)realloc(v, (nbVoitures + nbNouveauxVoitures) * sizeof(VOITURE));
    if (v == NULL) {
        ///Si la redimention a été échouée
        printf("Erreur lors du redimensionnement du tableau stockvoiture\n");
    } else {
        ///Modifier de la taille du tableau voitures v intiale
        nbVoitures += nbNouveauxVoitures;
        int i;
        ///Ajouter de nouvelles voitures
        for (i = nbVoitures - nbNouveauxVoitures; i < nbVoitures; i++) {
            printf("\nVOITURE %d\n", i);
            ///Ajouter dans le tableau v
            ajouterVoiture(v + i);
        }
    }
}

void remplirTabClient(CLIENT * c, int nbClients, VOITURE *v, int nbVoitures){
            int i;
            int code;
            VOITURE Vloue;
             for(i=0;i<nbClients;i++){

                printf("\nCLIENT \n");
                ajouterClient(c+i,v,nbVoitures);
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
            strcpy(nouveauResultat->nomClient, (c+j)->nom);
            strcpy(nouveauResultat->prenomClient, (c+j)->prenom);
            nouveauResultat->nbLocations = (c+j)->nombreLocations;
            int prix=0, v;
            printf("\n****************Nombre locations client %d = %d\n",j,(c+j)->nombreLocations);
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
            *(tableauResultats+nbResultats) = nouveauResultat;
            nbResultats++; // Augmenter le nombre de résultats
        }
}

void maxNbLocations(RESULTAT** tableauResultats, int nbClients){
    int indexMax = 0;
            int nbMax = (*tableauResultats+0)->nbLocations;
            printf("\n----------------------\n");
            int i;
            for (i = 1; i < nbClients; i++) {
                if ((*tableauResultats+i)->nbLocations > nbMax) {
                    nbMax = (*tableauResultats+i)->nbLocations;
                    indexMax = i;
                }
            }

            // Afficher les détails du client ayant le montant le plus élevé à payer
            printf("Client avec le nombre de location le plus élevé à payer :\n");
            printf("Nom et prénom du client : %s %s\n", (*tableauResultats+indexMax)->nomClient, tableauResultats[indexMax]->prenomClient);
            printf("Nombre de location : %d\n\n", (*tableauResultats+indexMax)->nbLocations);
}

void creerFichierClientsIndex(FILE**fp,FILE**fi)
{
    *fp=fopen("Clients","wb+");
    if( !*fp) exit(-1);
    *fi=fopen("ClientsIndex","wb+");
    if ( !*fi) exit(-1);
}


void remplirFichierClientsIndex(FILE*fp, FILE*fi, VOITURE*v,int nbVoitures,CLIENT * c, int nbClients)
{
    int x;
    int i;
    for (i=0;i<nbClients;i++){
        ajouterClient(c+i,v,nbVoitures);
        x=ftell(fp);
        fwrite(&x, sizeof(int),1,fi);
        ecrireUnClientDansFichier(fp,*(c+i));
    }

}

void afficherFichierClientsIndex(FILE*fp,FILE*fi,int nbClients)
{
    CLIENT c;
    int x,i;
    rewind(fi);rewind(fp);
    printf("\nAffichage Fichier index\n");

     while (fread(&x, sizeof(int), 1, fi) == 1) {
        fseek(fp, x, SEEK_SET); // Se positionner à l'offset x dans le fichier clients

        c = lireUnClientDuFichier(fp);
        afficherClient(c);
    }

}

void ecrireUnClientDansFichier(FILE*fp,CLIENT c)
{
     // Écriture des informations du client dans le fichier
    fwrite(&c.cin, sizeof(int), 1, fp);
    fwrite(c.nom, sizeof(char), 50, fp);
    fwrite(c.prenom, sizeof(char), 50, fp);
    fwrite(&c.telephone, sizeof(int), 1, fp);
    fwrite(&c.nombreLocations, sizeof(int), 1, fp);
    //fwrite(c.locations, sizeof(LOCATION), c.nombreLocations, fp);

    // Écriture des informations de chaque location
      int i;
     for ( i = 0; i < c.nombreLocations; ++i) {
        fwrite(&c.locations[i]->code, sizeof(int), 1, fp);
    }
}

// Fonction pour lire les données d'un client depuis un fichier
CLIENT lireUnClientDuFichier(FILE *fp) {
    CLIENT c;
    fread(&c.cin, sizeof(int), 1, fp);
    fread(c.nom, sizeof(char), 50, fp);
    fread(c.prenom, sizeof(char), 50, fp);
    fread(&c.telephone, sizeof(int), 1, fp);
    fread(&c.nombreLocations, sizeof(int), 1, fp);

    // Allocation de mémoire pour les locations
  ///  c.locations = (LOCATION **)malloc(c.nombreLocations * sizeof(LOCATION** ));
    if (c.locations == NULL) {
        perror("Allocation de mémoire a échoué");
        exit(-3);
    }
    int i ;
    for (i= 0; i < c.nombreLocations; ++i) {
        c.locations[i] = (LOCATION *)malloc(sizeof(LOCATION));
        if (c.locations[i] == NULL) {
            perror("Allocation de mémoire a échoué");
           /// libererMemoireLocations(&c);
            exit(-3);
        }

        fread(&c.locations[i]->code, sizeof(int), 1, fp);
       /// fread(&c.locations[i]->dateFin, sizeof(DATE), 1, fp);
    }

    return c;
}




