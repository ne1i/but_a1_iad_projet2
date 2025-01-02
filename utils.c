#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "headers/utils.h"
#include "headers/partie.h"

void nettoyer_stdin()
{
    int c = getchar();
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void initMotPoses(MotPoses *mot_poses, int capacite)
{
    mot_poses->capacite = capacite;
    mot_poses->nb_elements = 0;
    mot_poses->tab_mots = (char **)calloc(capacite, sizeof(char *));
    if (mot_poses->tab_mots == 0)
    {
        printf("Erreur de l'allocation de mémoire pour initialiser\n");
        return;
    }
}

int redimensionnerMotPoses(MotPoses *mot_poses, int nvlCapacite)
{
    if (nvlCapacite <= mot_poses->capacite)
    {
        printf("La nouvelle capacité doit être supérieure à l'ancienne\n");
        return -1;
    }

    char **nouveauTableau = (char **)calloc(nvlCapacite, sizeof(char *));
    if (nouveauTableau == NULL)
    {
        printf("Echec de l'allocation mémoire pour redimensionner\n");
        return -1;
    }

    for (int i = 0; i < mot_poses->nb_elements; i++)
    {
        nouveauTableau[i] = mot_poses->tab_mots[i];
    }

    free(mot_poses->tab_mots);

    mot_poses->tab_mots = nouveauTableau;
    mot_poses->capacite = nvlCapacite;

    return 0;
}

int ajouterMot(MotPoses *mot_poses, const char *mot)
{

    if (mot_poses->nb_elements >= mot_poses->capacite)
    {
        int nouvelleCapacite = mot_poses->capacite * 2;
        if (redimensionnerMotPoses(mot_poses, nouvelleCapacite) != 0)
        {
            printf("Impossible de redimensionner le tableau\n");
            return -1;
        }
    }

    mot_poses->tab_mots[mot_poses->nb_elements] = strdup(mot);
    if (mot_poses->tab_mots[mot_poses->nb_elements] == NULL)
    {
        printf("Echec de l'allocation mémoire pour le mot\n");
        return -1;
    }

    mot_poses->nb_elements++;
    return 0;
}
