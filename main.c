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
   /** stockvoiture=(VOITURE*)malloc(n*sizeof(VOITURE));
    for(i=0;i<n;i++)
        ajouterVoiture(&stockvoiture+i);

     for(i=0;i<n;i++)
        afficherVoiture(*(stockvoiture+i));
*/
    ajouterClient(&c1);
    afficherClient(c1);
    return 0;
}
