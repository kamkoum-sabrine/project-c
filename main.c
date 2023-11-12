#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
void main()
{
    int nbVoitures,i,nbClients;
    VOITURE *stockvoiture;
    CLIENT *clientsAgence;

    printf("Bienvenue dans votre Agence de voiture\n");
    printf("Combien de voiture voulez vous ajouter ? \n");
    scanf("%d",&nbVoitures);
    stockvoiture=(VOITURE*)malloc(nbVoitures*sizeof(VOITURE));
    printf("\n*************Remplissage*************\n");
    for(i=0;i<nbVoitures;i++){
        printf("\nVOITURE %d\n",i);
        ajouterVoiture(stockvoiture+i);
    }
    printf("\n************Affichage****************\n");
     for(i=0;i<nbVoitures;i++){
        printf("\nVOITURE %d\n",i);
        afficherVoiture(*(stockvoiture+i));
     }
    /** int codeSupp;
     printf("*******Suppression d'une voiture***********\n")
     printf("Donner le code de voiture à supprimer ");
     scanf("%d",&codeSupp);
     supprimerVoiture(stockvoiture,nbVoitures, codeSupp);
    printf("Affichage après suppression \n");
    for(i=0;i<nbVoitures;i++){
        printf("\nVOITURE %d\n",i);
        afficherVoiture(*(stockvoiture+i));
     }
    **/
    printf("Combien de client voulez vous ajouter ? \n");
    scanf("%d",&nbClients);
    clientsAgence=(CLIENT*)malloc(nbClients*sizeof(CLIENT));
    int code;
    VOITURE Vloue;
    printf("\n*************Remplissage*************\n");
    for(i=0;i<nbClients;i++){
        printf("\nCLIENT %d\n",i);
        ajouterClient(clientsAgence+i);
        do {
            printf("Donner le code de voiture a louer pour le client %s %s ",(clientsAgence+i)->nom, (clientsAgence+i)->prenom);
            scanf("%d",&code);

            Vloue = rechercherVoitureParCode(code,stockvoiture,nbVoitures);
            if (Vloue.code==0){
                printf("Voiture introuvable !!\n");
            }
        } while (Vloue.code==0);

        affecterClientToVoiture(clientsAgence+i,Vloue);
    }
    printf("\n************Affichage****************\n");
    for(i=0;i<nbClients;i++){
        printf("\nCLIENT %d\n",i);
        afficherClient(*(clientsAgence+i));
    }
    int choix,codeVoiture,choix2;
    VOITURE Voit;
// Mise à jour du tableau de voitures
    printf("Voulez-vous mettre à jour le tableau de voitures ? (1 pour Oui, 0 pour Non) : ");
    scanf("%d", &choix);

    if (choix) {
        // Demandez le code de la voiture à mettre à jour
        printf("Veuillez entrer le code de la voiture à mettre à jour : ");
        scanf("%d", &(codeVoiture));

        // Demandez les nouvelles informations de la voiture
        printf("Veuillez entrer les nouvelles informations de la voiture :\n");
        printf("Saisissez le nouveau code de la voiture : ");
        scanf("%d", &Voit.code);

        printf("Saisissez le modèle de la nouvelle voiture : ");
        scanf(" %s", &Voit.modele);

        printf("Saisissez la marque de la nouvelle voiture : ");
         scanf(" %s", &Voit.marque);

       printf("Saisissez l'année de fabrication de la nouvelle voiture : ");
       scanf("%d", &Voit.annee);

      printf("Saisissez le prix de location de la nouvelle voiture : ");
      scanf("%f", &Voit.prixLocation);


        // Appelez la fonction miseAJour pour mettre à jour la voiture dans le tableau
        miseAJour(stockvoiture, nbVoitures, codeVoiture, Voit);
    }

    // Affichage du tableau de voitures après la mise à jour
    printf("\n************Affichage après mise à jour****************\n");
    for(i=0;i<nbVoitures;i++)
      afficherVoiture(*(stockvoiture+i));
printf("Voulez-vous supprimer une voiture du tableau ? (1 pour Oui, 0 pour Non) : ");
    scanf("%d", &choix2);

    if (choix2) {
        // Demandez le code de la voiture à supprimer
        printf("Veuillez entrer le code de la voiture à supprimer : ");
        scanf("%d", &codeVoiture);

        // Appelez la fonction supprimerVoiture pour supprimer la voiture du tableau
        supprimerVoiture(stockvoiture, nbVoitures, codeVoiture);
        nbVoitures--;
        // Affichage du tableau de voitures après la suppression
        printf("\n************Affichage après suppression****************\n");
        for(i=0;i<nbVoitures;i++)
        afficherVoiture(*(stockvoiture+i));
    }


    printf("\nFIN\n");

    getch();
}
