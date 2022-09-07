#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv )
{
    int randomNB = 0, nbEntered = 0, tries = 0, restart = 0, lvl = 2;
    int max = 100;
    const int MIN = 1;

    srand(time(NULL));

    // Sélection de la difficulté

    printf("Choisissez un niveau de difficulté :\n");
    printf("1 : entre 1 et 10\n2 : entre 1 et 100\n3 : entre 1 et 1000\n");
    scanf("%d", &lvl);

    switch(lvl)
    {
    case 1:
        max = 10;
        break;
    case 2:
        max = 100;
        break;
    case 3:
        max = 1000;
        break;
    default:
        printf("Niveau non reconnu. Je choisis pour vous le niveau 2 (entre 1 et 100).\n");
        max = 100;
    }

    // D�but de la boucle qui permet de faire plusieurs parties
    do
    {
        // Initialisations pour la partie
        tries = 0;
        randomNB = (rand() % (max - MIN + 1)) + MIN;

        do
        {
            printf("Quel est le nombre ? ");
            scanf("%d", &nbEntered);
            tries++;

            if (randomNB > nbEntered)
                printf("C'est plus !\n\n");
            else if (randomNB < nbEntered)
                printf("C'est moins !\n\n");
            else
                printf ("Bravo, vous avez trouve le nombre mystere en %d coups !!!\n\n", tries);

        } while (nbEntered != randomNB);

        // Fin de la partie, on demande si on veut rejouer
        printf("Voulez-vous faire une autre partie (1 = oui, 0 = non) ? ");
        scanf("%d", &restart);

    } while (restart);

}
