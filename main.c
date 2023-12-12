#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
void main()
{
    int nbVoitures,i,nbClients;
    VOITURE *stockvoiture;
    CLIENT *clientsAgence;
    /// Déclaration d'un tableau dynamique d'adresses de RESULTAT
    RESULTAT ** tableauResultats;
    int nbResultats = 0; // Nombre initial d'éléments dans le tableau
    int capaciteResultats = 5; // Capacité initiale du tableau
    tableauResultats = (RESULTAT **)malloc(capaciteResultats * sizeof(RESULTAT *));
    printf("\nBienvenue dans votre Agence de voiture\n\n");
    printf("Combien de voiture voulez vous ajouter ? ");
    scanf("%d",&nbVoitures);
    stockvoiture = allocationvoiture(nbVoitures);
    printf("\n*************Ajout des voitures*************\n");
    remplirTabVoiture (stockvoiture, nbVoitures);
    int option;
    do {

        printf("\n\n*********Menu*********\n");
        printf("1-Ajouter des clients\n");
        printf("2-Affichage des voitures disponibles\n");
        printf("3-Affichage des clients \n");
        printf("4-Ajouter des voitures\n");
        printf("5-Supprimer une voiture\n");
        printf("6-Mettre à une voiture\n");
        printf("7-Afficher le client qui a le nombre de locations de plus élevé\n");
        printf("8-Quitter\n");
        printf("Choisissez une option ");
        scanf("%d",&option);
        int codeVoiture,choix2;
        VOITURE Voit;
        switch (option) {
        case 1 :
            printf("\n\nCombien de client voulez vous ajouter ? ");
            scanf("%d",&nbClients);
            clientsAgence=allocationclient(nbClients);
            printf("\n*************Ajout des clients*************\n");
            remplirTabClient(clientsAgence,nbClients, stockvoiture, nbVoitures);
        break;
        case 2 :
            printf("\n************Affichage des voitures****************\n");
            afficherTabVoiture(stockvoiture, nbVoitures);
            break;
        case 3:

            printf("\n************Affichage****************\n");
        for(i=0;i<nbClients;i++){
            printf("\nCLIENT %d\n",i);
            afficherClient(*(clientsAgence+i));
        } break;
        case 4:
            // Utilisation de realloc pour redimensionner stockvoiture
            printf("\nCombien de voitures supplémentaires voulez-vous ajouter ? ");
            int nbNouveauxVoitures;
            scanf("%d", &nbNouveauxVoitures);
            reallocVoiture(stockvoiture, nbVoitures, nbNouveauxVoitures);
         break;
          case 5:
            printf("Veuillez entrer le code de la voiture à supprimer : ");
            scanf("%d", &codeVoiture);
            supprimerVoiture(stockvoiture, nbVoitures, codeVoiture);
            nbVoitures--;
         break;
        case 6:
            miseAJour(stockvoiture, nbVoitures, codeVoiture);
          break;
          case 7:
            if (tableauResultats == NULL) {
                printf("Erreur lors de l'allocation du tableau de résultats\n");
                exit(-1);
            }
            remplirTabResultat(tableauResultats, nbResultats,clientsAgence, nbClients,capaciteResultats);
             // Trouver le client avec le montant le plus élevé à payer
            maxNbLocations(tableauResultats, nbClients);
            ///free(tableauResultats); // Libérer la mémoire allouée pour le tableau de Resultat
            // ... (autres opérations sur les résultats)

            // Libérer la mémoire allouée pour chaque résultat
           /** for (i = 0; i < nbResultats; i++) {
                free(tableauResultats[i]);
            }**/

            // Libérer le tableau des adresses de résultats
            ///free(tableauResultats);
          break;
        default: printf("Choix invalid \n");
        }
    } while (option!=8);


    printf("\nFIN\n");

    getch();
    }
