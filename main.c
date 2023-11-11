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


    printf("\nFIN\n");

    getch();
}
