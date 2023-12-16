#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bib.h"
int main()
{
    srand((unsigned int)time(NULL));

    // Générer et retourner un nombre aléatoire de 5 chiffres
    ///printf("%\n",rand() % 90000 + 10000) ;
     int nombreAleatoire = 0;
     int j;

    int nbVoitures,i,nbClients;
    VOITURE *stockvoiture;
    CLIENT *clientsAgence;
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
    int codeVoiture;
    int option;

    FILE *fp, *fi;
    CLIENT c;
    creerFichierClientsIndex(&fp, &fi);
    int option1, option2;
    do {
        printf("*** MENU PRINCIPAL *****\n");
        printf("1 - Manipuler les clients\n");
        printf("2 - Manipuler les voitures\n");
        printf("3 - Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                do {
                    printf("\n***** MENU CLIENTS *****\n");
                    printf("1 - Afficher les clients (a partir du fichier)\n");
                    printf("2 - Ajouter des clients\n");
                    printf("3 - Modifier un client\n");
                    printf("4 - Trouver le client avec le plus de locations\n");
                    printf("5 - Afficher fichier index\n");
                    printf("6 - Revenir au menu principal\n");
                    printf("Choisissez une option : ");
                    scanf("%d", &option1);

                    switch (option1) {
                        case 1:
                             printf("\n************Affichage****************\n");
                            afficherFichierClientsIndex(fp, fi,nbClients);
                        break;
                        case 2:
                            printf("Vous avez choisi d'ajouter des clients.\n");
                            printf("\n\nCombien de client voulez vous ajouter ? ");
                            scanf("%d",&nbClients);
                            clientsAgence=allocationclient(nbClients);
                            printf("\n*************Ajout des clients*************\n");
                            remplirFichierClientsIndex (fp, fi,stockvoiture,nbVoitures,clientsAgence,nbClients);
                         break;
                            break;
                        case 3:
                            printf("Vous avez choisi de mettre à jour un client.\n");
                             int posAChercher, x;
                            printf("Saisir la position du client à modifier ");
                            scanf("%d",&posAChercher);
                            fseek(fi, (posAChercher-1)*sizeof(int),0);
                            fread(&x, sizeof(int), 1, fi);
                            fseek(fp,x,0);
                            c=lireUnClientDuFichier(fp);
                            printf("Client avant mise a jour\n");
                            afficherClient(c);
                            // Modifier les données du client c (par exemple, mettre à jour les informations)
                            printf("Saisir les nouveaux données du client \n");
                            ajouterClient(&c,stockvoiture,nbVoitures );
                            // Écrire les données mises à jour dans le fichier principal
                            fseek(fp, x, 0); // Se repositionner au même emplacement dans le fichier principal
                            ecrireUnClientDansFichier(fp, c); // Écrire les données du client modifié dans le fichier
                     break;
                     case 4:
                            printf("Vous avez choisi de trouver le client avec le plus de locations.\n");
                             if (tableauResultats == NULL) {
                             printf("Erreur lors de l'allocation du tableau de résultats\n");
                             exit(-1);
                              }
                              remplirTabResultat(tableauResultats, nbResultats,clientsAgence, nbClients,capaciteResultats);
                             // Trouver le client avec le montant le plus élevé à payer
                            maxNbLocations(tableauResultats, nbClients);
                           // Libérer la mémoire allouée pour chaque résultat
                           for (i = 0; i < nbResultats; i++) {
                                free(tableauResultats[i]);
                            }

                     break;
                     case 5 : printf("Affichage du fichier index");
                        CLIENT c;
                        int i;
                        rewind(fi);rewind(fp);
                        printf("\nAffichage Fichier index\n");
                         while (fread(&x, sizeof(int), 1, fi) == 1) {
                            printf("\n%d", x);
                            fseek(fp, x, SEEK_SET); // Se positionner à l'offset x dans le fichier clients
                        }
                        break;
                    case 6 : printf("revenir au menu principal");
                            break;
                        default:
                            printf("Choix invalide. Veuillez sélectionner une option valide.\n");
                    }
                } while (option1 != 6);


            case 2:
                do {
                    printf("\n***** MENU VOITURES *****\n");
                    printf("1 - Afficher les voitures\n");
                    printf("2 - Ajouter une voiture\n");
                    printf("3 - Supprimer une voiture\n");
                    printf("4 - Mettre à jour une voiture\n");
                    printf("5 - Revenir au menu principal\n");
                    printf("Choisissez une option : ");
                    scanf("%d", &option2);

                    switch (option2) {
                        case 1:
                            printf("\n************Affichage des voitures****************\n");
                             afficherTabVoiture(stockvoiture, nbVoitures);
                             break;

                        case 2:
                            printf("Vous avez choisi d'ajouter une voiture.\n");
                            /**Utilisation de realloc pour redimensionner stockvoiture**/
                           int nbNouveauxVoitures;
                           printf("\nCombien de voitures supplémentaires voulez-vous ajouter ? ");
                           scanf("%d", &nbNouveauxVoitures);
                           reallocVoiture(stockvoiture, nbVoitures, nbNouveauxVoitures);
                             // Ajouter la logique pour ajouter une voiture
                            break;
                        case 3:

                            printf("Vous avez choisi de supprimer une voiture.\n");
                            printf("Veuillez entrer le code de la voiture à supprimer : ");
                           scanf("%d", &codeVoiture);
                           printf("CODE DE VOITURE %d\n",codeVoiture);
                          supprimerVoiture(stockvoiture, nbVoitures, codeVoiture);
                          nbVoitures--;
                        break;
                        case 4:
                            printf("Vous avez choisi de mettre à jour une voiture.\n");
                            miseAJour(stockvoiture, nbVoitures, codeVoiture);
                            break;
                        case 5:
                            printf("Retour au menu principal...\n");
                            break;
                        default:
                            printf("Choix invalide. Veuillez sélectionner une option valide.\n");
                    }
                } while (option2 != 5);
                break;
            case 3:
                printf("Merci d'avoir utilisé notre service de location de voitures.\n");
                break;
            default:
                printf("Choix invalide. Veuillez sélectionner une option valide.\n");
        }


       }while (option!= 3);
    printf("\nFIN\n");

    return 0;
    }
