#include "headers/partie.h"
#include "headers/joueur.h"

void initPartie(Partie *p)
{
    initPaquet(&p->paquet);
    Joueur j1 = p->tab_joueurs[0];
    Joueur j2 = p->tab_joueurs[1];
    initJoueur(&j1, p);
    initJoueur(&j2, p);
}