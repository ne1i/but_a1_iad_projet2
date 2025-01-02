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
    Joueur *j1 = &p->tab_joueurs[0];
    Joueur *j2 = &p->tab_joueurs[1];

    printf("1 : ");
    afficheMain(&j1->main);
    printf("2 : ");
    afficheMain(&j2->main);
    printf("\n");

    Chevalet motJ1[TAILLE_PREMIER_MOT + 1] = {0};
    while (!mainContientChaine(&j1->main, motJ1) || !verifierMotDepart(motJ1, f))
    {
        printf("1> ");
        scanf("%5s", motJ1);
        nettoyer_stdin();
    }
    joueurPose(j1, motJ1, mot_poses);

    Chevalet motJ2[TAILLE_PREMIER_MOT + 1] = {0};
    while (!mainContientChaine(&j2->main, motJ2) || !verifierMotDepart(motJ2, f) || !motDejaPose(mot_poses, motJ2))
    {
        printf("2> ");
        scanf("%5s", motJ2);
        nettoyer_stdin();
    }
    joueurPose(j2, motJ2, mot_poses);

    printf("1 : ");
    afficheMain(&j1->main);
    printf("2 : ");
    afficheMain(&j2->main);
    printf("\n");
    while (1)
    {
    }
}

int verifierMotDepart(const char *mot, FILE *f)
{
    if (strlen(mot) != TAILLE_PREMIER_MOT)
    {
        return 0;
    }

    if (!dictionnaireContient(mot, f))
    {
        return 0;
    }

    return 1;
}

int verifierMot(const char *mot, FILE *f)
{
    if (strlen(mot) > NB_CHEVALET_RAIL)
    {
        return 0;
    }

    if (motDejaPose)
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
            return 0;
        }
    }
    return 1;
}