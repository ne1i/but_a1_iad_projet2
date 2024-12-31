#include <stdio.h>

#include "headers/partie.h"
#include "headers/dictionnaire.h"

int main()
{
    FILE *f = fopen(DICT_FILE_NAME, "r");
    if (f == NULL)
    {
        printf("fichier non accessible\n");
        return -1;
    }

    Partie p = {0};
    initPartie(&p);
    boucleDeJeu(&p, f);
    return 0;
}