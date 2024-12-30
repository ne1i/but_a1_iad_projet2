#include <stdio.h>
#include <string.h>

#include "headers/partie.h"
#include "headers/utils.h"

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

void boucleDeJeu(Partie *p)
{
    Joueur *j1 = &p->tab_joueurs[0];
    Joueur *j2 = &p->tab_joueurs[1];

    printf("1 : ");
    afficheMain(&j1->main);
    printf("2 : ");
    afficheMain(&j2->main);
    printf("\n");

    Chevalet motJ1[TAILLE_PREMIER_MOT + 1] = {0};
    while (!verifierMot(motJ1))
    {
        printf("1> ");
        scanf("%5s", motJ1);
    }

    Chevalet motJ2[TAILLE_PREMIER_MOT + 1] = {0};
    while (!verifierMot(motJ2))
    {
        printf("2> ");
        scanf("%5s", motJ2);
    }

    while (1)
    {
    }
}

int verifierMot(const char *mot)
{
    if (strlen(mot) != TAILLE_PREMIER_MOT)
    {
        return 0;
    }

    if (!dict_contains(mot))
    {
        return 0;
    }

    return 1;

    // Vérifier que le mot est dans le dico
}