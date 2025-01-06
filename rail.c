#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "headers/rail.h"
#include "headers/partie.h"

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

void remplirRail(Rail *rail, const char *mot1, const char *mot2)
{
    char motConcat[(TAILLE_PREMIER_MOT * 2) + 1] = {0};
    if (strcmp(mot1, mot2) < 0)
    {
        strcpy(motConcat, mot1);
        strcpy(&motConcat[TAILLE_PREMIER_MOT], mot2);
        strcpy(rail->chevalets_recto, motConcat);
    }
    if (strcmp(mot1, mot2) > 0)
    {
        strcpy(motConcat, mot2);
        strcpy(&motConcat[TAILLE_PREMIER_MOT], mot1);
        strcpy(rail->chevalets_recto, motConcat);
    }
    strcpy(rail->chevalets_verso, inverseStr(rail->chevalets_recto));
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

int railContient(const Rail *rail, Chevalet *chaine, char recto_verso, char gauche_droite)
{
    int len = strlen(chaine);
    if (recto_verso == 'R')
    {
        for (int i = 0;)
    }
    if (recto_verso == 'V')
    {
    }
    return 0;
}