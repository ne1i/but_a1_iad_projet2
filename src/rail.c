#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "partie.h"

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

int railContient(const Rail *rail, const Chevalet *chaine, const char recto_verso, const char gauche_droite)
{
    int len = strlen(chaine);
    int lenRail = NB_CHEVALET_RAIL;

    const Chevalet *cible = (recto_verso == 'R') ? rail->chevalets_recto : rail->chevalets_verso;

    if (gauche_droite == 'G')
    {

        for (int i = 0; i < len; ++i)
        {
            if (cible[i] != chaine[i])
            {
                return 0;
            }
        }
    }
    else if (gauche_droite == 'D')
    {

        for (int i = 0; i < len; ++i)
        {
            if (cible[lenRail - len + i] != chaine[i])
            {
                return 0;
            }
        }
    }
    else
    {

        return 0;
    }

    return 1;
}

Chevalet *ejecterRail(Rail *rail, Chevalet *chaine, char recto_verso, char gauche_droite)
{
    int len = strlen(chaine);
    int lenRail = NB_CHEVALET_RAIL;
    Chevalet *chevalets_ejectes = (Chevalet *)calloc(len, sizeof(char));
    if (chevalets_ejectes == NULL)
    {
        puts("Erreur dans l'allocation de mémoire");
        return NULL;
    }

    Chevalet *cible = (recto_verso == 'R') ? rail->chevalets_recto : rail->chevalets_verso;
    Chevalet *autre = (recto_verso == 'R') ? rail->chevalets_verso : rail->chevalets_recto;

    if (gauche_droite == 'G')
    {

        for (int i = 0; i < len; ++i)
        {
            chevalets_ejectes[i] = cible[lenRail - len + i];
        }
        for (int i = lenRail - 1; i >= len; --i)
        {
            cible[i] = cible[i - len];
        }
        for (int i = 0; i < len; ++i)
        {
            cible[i] = chaine[i];
        }
    }
    else if (gauche_droite == 'D')
    {

        for (int i = 0; i < len; ++i)
        {
            chevalets_ejectes[i] = cible[i];
        }

        for (int i = 0; i < lenRail - len; ++i)
        {
            cible[i] = cible[i + len];
        }

        for (int i = 0; i < len; ++i)
        {
            cible[lenRail - len + i] = chaine[i];
        }
    }
    char *temp = inverseStr(cible);
    strcpy(autre, temp);
    free(temp);

    return chevalets_ejectes;
}
