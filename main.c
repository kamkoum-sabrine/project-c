#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
void main()
{
    int nbVoitures,i,nbClients;
    VOITURE *stockvoiture;
    CLIENT *clientsAgence;

    printf("\nBienvenue dans votre Agence de voiture\n");
    printf("Combien de voiture voulez vous ajouter ? ");
    scanf("%d",&nbVoitures);
    stockvoiture=(VOITURE*)malloc(nbVoitures*sizeof(VOITURE));
    printf("\n*************Ajout des voitures*************\n");
    for(i=0;i<nbVoitures;i++){
        printf("\nVOITURE %d\n",i);
        ajouterVoiture(stockvoiture+i);
    }


      int option;
    do {

        printf("*********Menu*********\n");
        printf("1-Ajouter des clients\n");
        printf("2-Affichage des voitures disponibles\n");
        printf("3-Affichage des clients \n");
        printf("4-Supprimer une voiture\n");
        printf("5-Mettre à une voiture\n");
        printf("6-Quitter\n");
        printf("Choisissez une option ");
        scanf("%d",&option);
        int codeVoiture,choix2;
        VOITURE Voit;
        switch (option) {
        case 1 :
            printf("\n\nCombien de client voulez vous ajouter ? ");
            scanf("%d",&nbClients);
            clientsAgence=(CLIENT*)malloc(nbClients*sizeof(CLIENT));
            int code;
            VOITURE Vloue;
            printf("\n*************Ajout des clients*************\n");
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
        } break;


        case 2 :
            printf("\n************Affichage des voitures****************\n");
             for(i=0;i<nbVoitures;i++){
                printf("\nVOITURE %d\n",i);
                afficherVoiture(*(stockvoiture+i));
             } break;
        case 3:

            printf("\n************Affichage****************\n");
        for(i=0;i<nbClients;i++){
            printf("\nCLIENT %d\n",i);
            afficherClient(*(clientsAgence+i));
        } break;
        case 4:
           printf("Veuillez entrer le code de la voiture à supprimer : ");
            scanf("%d", &codeVoiture);
            supprimerVoiture(stockvoiture, nbVoitures, codeVoiture);
            nbVoitures--;

         break;
        case 5:
            printf("Veuillez entrer le code de la voiture à mettre à jour : ");
            scanf("%d", &(codeVoiture));
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
            miseAJour(stockvoiture, nbVoitures, codeVoiture, Voit);
          break;
        default: printf("Choix invalid \n");
        }
    } while (option!=6);


    printf("\nFIN\n");

    getch();
    }
