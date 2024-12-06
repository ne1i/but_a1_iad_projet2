#include "headers/joueur.h"
#include "headers/partie.h"

void initJoueur(Joueur *j, Partie *p)
{
    for (int i = 0; i < MAX_NB_CHEVALET_MAIN; ++i)
    {
        j->main.chevalets[i] = p->paquet.chevalets[p->paquet.nb_chevalet - i - 1];
        --p->paquet.nb_chevalet;
    }
}