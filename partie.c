#include <stdio.h>
#include <string.h>

#include "headers/utils.h"
#include "headers/partie.h"
#include "headers/dictionnaire.h"
#include "headers/paquet.h"

void initPartie(Partie *p)
{
    Paquet *paq = &p->paquet;
    initPaquet(paq);

    Main m1 = {0};
    Main m2 = {0};
    initMain(&m1, paq);
    initMain(&m2, paq);

    Joueur *j1 = &p->tab_joueurs[0];
    Joueur *j2 = &p->tab_joueurs[1];
    initJoueur(j1, m1);
    initJoueur(j2, m2);

    Rail *rail = &p->rail;
    initRail(rail);
}

void boucleDeJeu(Partie *p, FILE *f, MotPoses *mot_poses)
{
    int nb_joueur_courant = 1;
    Joueur *j1 = &p->tab_joueurs[0];
    Joueur *j2 = &p->tab_joueurs[1];
    Joueur *joueur_courant = j1;
    // joueurPose(joueur_courant, mot_poses, &p->rail, f, nb_joueur_courant);
    printf("1 : ");
    afficherMain(&j1->main);
    printf("2 : ");
    afficherMain(&j2->main);
    printf("\n");

    joueurPoseDepart(j1, mot_poses, &p->rail, f, 1);
    joueurPoseDepart(j2, mot_poses, &p->rail, f, 2);
    printf("\n");
    remplirRail(&p->rail, mot_poses->tab_mots[0], mot_poses->tab_mots[1]);
    if (strcmp(mot_poses->tab_mots[0], mot_poses->tab_mots[1]) < 0) // le joueur ayant posé le plus petit mot joue en premier
    {
        nb_joueur_courant = 1;
        joueur_courant = j1;
    }

    else
    {
        nb_joueur_courant = 2;
        joueur_courant = j2;
    }

    afficherEtatPartie(p);
    while (j1->main.nb_chevalet_restants != 0 || j2->main.nb_chevalet_restants != 0)
    {
        joueurPose(joueur_courant, mot_poses, &p->rail, f, nb_joueur_courant);
    }
}

int verifierMotDepart(const char *mot, FILE *f, MotPoses *mot_poses)
{
    if (strlen(mot) != TAILLE_PREMIER_MOT)
    {
        return 0;
    }

    if (motDejaPose(mot_poses, mot))
    {
        return 0;
    }

    if (!dictionnaireContient(mot, f))
    {
        return 0;
    }

    return 1;
}

int verifierMot(const char *mot, FILE *f, MotPoses *mot_poses)
{
    if (strlen(mot) > NB_CHEVALET_RAIL)
    {
        return 0;
    }

    if (motDejaPose(mot_poses, mot))
    {
        return 0;
    }

    if (!dictionnaireContient(mot, f))
    {
        return 0;
    }
    return 1;
}

int motDejaPose(const MotPoses *mot_poses, const char *mot)
{
    for (int i = 0; i < mot_poses->nb_elements; ++i)
    {
        if (strcmp(mot_poses->tab_mots[i], mot) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void afficherEtatPartie(Partie *p)
{
    printf("1 : ");
    afficherMain(&p->tab_joueurs[0].main);
    printf("2 : ");
    afficherMain(&p->tab_joueurs[1].main);
    afficherRail(&p->rail);
    printf("\n");
}