#include "headers/partie.h"
#include "headers/joueur.h"

void initPartie(Partie *p)
{
    Paquet *paq = &p->paquet;
    initPaquet(paq);

    Main m1;
    Main m2;
    initMain(&m1, paq);
    initMain(&m2, paq);

    Joueur *j1 = &p->tab_joueurs[0];
    Joueur *j2 = &p->tab_joueurs[1];
    initJoueur(j1, m1);
    initJoueur(j2, m2);
}