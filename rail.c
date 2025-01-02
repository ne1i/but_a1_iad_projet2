#include <string.h>
#include <stdio.h>

#include "headers/rail.h"

void initRail(Rail *rail)
{
    memset(rail->chevalets_recto, 0, sizeof(rail->chevalets_recto));
    memset(rail->chevalets_verso, 0, sizeof(rail->chevalets_verso));
}

void afficherRail(const Rail *rail)
{
    printf("R : ");
    for (int i = 0; i < NB_CHEVALET_RAIL; ++i)
    {
        printf("%c", rail->chevalets_recto[i]);
    }
    printf("\n");

    printf("V : ");
    for (int i = 0; i < NB_CHEVALET_RAIL; ++i)
    {
        printf("%c", rail->chevalets_verso[i]);
    }
    printf("\n");
}

void ajouterMotRail(Rail *rail, const char *mot, char cote)
{
    if (cote == 'R')
    {
    }

    if (cote == 'V')
    {
    }
}