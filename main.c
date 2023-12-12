#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
void main()
{
    int nbVoitures,i,nbClients;
    VOITURE *stockvoiture;
    CLIENT *clientsAgence;
    RESULTAT ** tableauResultats;
    int nbResultats = 0; // Nombre initial d'�l�ments dans le tableau
    int capaciteResultats = 5; // Capacit� initiale du tableau

    tableauResultats = (RESULTAT **)malloc(capaciteResultats * sizeof(RESULTAT *));
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

        printf("\n\n*********Menu*********\n");
        printf("1-Ajouter des clients\n");
        printf("2-Affichage des voitures disponibles\n");
        printf("3-Affichage des clients \n");
        printf("4-Ajouter des voitures\n");
        printf("5-Supprimer une voiture\n");
        printf("6-Mettre � une voiture\n");
        printf("7-Afficher le client qui a le nombre de locations de plus �lev�\n");
        printf("8-Quitter\n");
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
            // Utilisation de realloc pour redimensionner stockvoiture
            printf("\nCombien de voitures suppl�mentaires voulez-vous ajouter ? ");
            int newCars;
            scanf("%d", &newCars);

            stockvoiture = (VOITURE *)realloc(stockvoiture, (nbVoitures + newCars) * sizeof(VOITURE));
            if (stockvoiture == NULL) {
                printf("Erreur lors du redimensionnement du tableau stockvoiture\n");
            } else {
                nbVoitures += newCars;
                for (i = nbVoitures - newCars; i < nbVoitures; i++) {
                    printf("\nVOITURE %d\n", i);
                    ajouterVoiture(stockvoiture + i);
                }
            }
         break;
          case 5:
           printf("Veuillez entrer le code de la voiture � supprimer : ");
            scanf("%d", &codeVoiture);
            supprimerVoiture(stockvoiture, nbVoitures, codeVoiture);
            nbVoitures--;

         break;
        case 6:
            printf("Veuillez entrer le code de la voiture � mettre � jour : ");
            scanf("%d", &(codeVoiture));
            printf("Veuillez entrer les nouvelles informations de la voiture :\n");
            printf("Saisissez le nouveau code de la voiture : ");
            scanf("%d", &Voit.code);

            printf("Saisissez le mod�le de la nouvelle voiture : ");
            scanf(" %s", &Voit.modele);

            printf("Saisissez la marque de la nouvelle voiture : ");
             scanf(" %s", &Voit.marque);

           printf("Saisissez l'ann�e de fabrication de la nouvelle voiture : ");
           scanf("%d", &Voit.annee);

          printf("Saisissez le prix de location de la nouvelle voiture : ");
          scanf("%f", &Voit.prixLocation);
            miseAJour(stockvoiture, nbVoitures, codeVoiture, Voit);
          break;
          case 7:
             // D�claration d'un tableau dynamique d'adresses de RESULTAT


            if (tableauResultats == NULL) {
                printf("Erreur lors de l'allocation du tableau de r�sultats\n");
                exit(-1);
            }
            // Exemple d'ajout d'un r�sultat dans le tableau
            // Supposons que vous ayez un nouveau r�sultat � ajouter
           int j;
            RESULTAT *nouveauResultat;
            for (j=0; j<nbClients; j++){
                nouveauResultat = (RESULTAT *)malloc(sizeof(RESULTAT));
                if (nouveauResultat == NULL) {
                    printf("Erreur lors de l'allocation d'un nouveau r�sultat\n");
                    exit(-2);
                }
                strcpy(nouveauResultat->nomClient, clientsAgence[j].nom);
                strcpy(nouveauResultat->prenomClient, clientsAgence[j].prenom);
                nouveauResultat->nbLocations = clientsAgence[j].nombreLocations;
                int prix=0, v;
                printf("\n****************Nombre locations client %d = %d\n",j,clientsAgence[j].nombreLocations);
               /** for(v=0;v<clientsAgence[j].nombreLocations;v++){
                  ///  prix+=clientsAgence[i].locations[v]->voitureLouee->prixLocation;
                 /// c->locations[c->nombreLocations]->voitureLouee->code

                    printf("\n***********prix location = %d\n",clientsAgence[j].locations[v]->voitureLouee->prixLocation);
                    prix +=  clientsAgence[j].locations[v]->voitureLouee->prixLocation;
                }
            **/
                // V�rifier si le tableau a besoin d'�tre redimensionn�
                if (nbResultats >= capaciteResultats) {
                    capaciteResultats *= 2; // Double la capacit� du tableau
                    tableauResultats = (RESULTAT **)realloc(tableauResultats, capaciteResultats * sizeof(RESULTAT *));
                    if (tableauResultats == NULL) {
                        printf("Erreur lors du redimensionnement du tableau de r�sultats\n");
                        exit(-3);
                    }
                }

                // Ajouter l'adresse du nouveau r�sultat dans le tableau
                tableauResultats[nbResultats] = nouveauResultat;
                nbResultats++; // Augmenter le nombre de r�sultats

            }
             // Trouver le client avec le montant le plus �lev� � payer
            int indexMax = 0;
            int nbMax = tableauResultats[0]->nbLocations;
            printf("\n----------------------\n");
            printf("Le nombre de location max = %d\n",nbMax);
            int i;
            for (i = 1; i < nbClients; i++) {
                if (tableauResultats[i]->nbLocations > nbMax) {
                    nbMax = tableauResultats[i]->nbLocations;
                    indexMax = i;
                }
            }

            // Afficher les d�tails du client ayant le montant le plus �lev� � payer
            printf("Client avec le nombre de location le plus �lev� � payer :\n");
            printf("Nom et pr�nom du client : %s %s\n", tableauResultats[indexMax]->nomClient, tableauResultats[indexMax]->prenomClient);
            printf("Nombre de location : %d\n\n", tableauResultats[indexMax]->nbLocations);

            ///free(tableauResultats); // Lib�rer la m�moire allou�e pour le tableau de Resultat
            // ... (autres op�rations sur les r�sultats)

            // Lib�rer la m�moire allou�e pour chaque r�sultat
           /** for (i = 0; i < nbResultats; i++) {
                free(tableauResultats[i]);
            }**/

            // Lib�rer le tableau des adresses de r�sultats
            ///free(tableauResultats);
          break;
        default: printf("Choix invalid \n");
        }
    } while (option!=8);


    printf("\nFIN\n");

    getch();
    }
