#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
int main()
{
    int n,i;
    VOITURE *stockvoiture;

    VOITURE v1;
    CLIENT c1;
  ///  ajouterVoiture(&v1);
   /// afficherVoiture(v1);

    printf("Salut ! Combien de voiture voulez vous ajouter ? ");
    scanf("%d",&n);
    ///remplirTabVoiture(stockvoiture,n);
  ///  afficherTabVoiture(stockvoiture,n);
    stockvoiture=(VOITURE*)malloc(n*sizeof(VOITURE));
    for(i=0;i<n;i++)
        ajouterVoiture(stockvoiture+i);

     for(i=0;i<n;i++)
        afficherVoiture(*(stockvoiture+i));

    ajouterClient(&c1);
    int code;
    VOITURE Vloue;
    do {
        printf("Donner le code de voiture a louer pour le client %s ",c1.nom);
        scanf("%d",&code);

        Vloue = rechercherVoitureParCode(code,stockvoiture,n);
        if (Vloue.code==0){
            printf("Voiture introuvable !!\n");
        }
    } while (Vloue.code==0);
    affecterClientToVoiture(&c1,Vloue);


   /// ajouterClient(&c1);
  ///  afficherClient(c1);
    return 0;
}
