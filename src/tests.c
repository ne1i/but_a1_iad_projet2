#include <assert.h>

#include "tests.h"

void testPartie(Partie p)
{
    Paquet paquet = p.paquet;
    Joueur *j1 = &p.tab_joueurs[0];
    Joueur *j2 = &p.tab_joueurs[1];
    Main m1 = j1->main;
    Main m2 = j2->main;

    retirerChevaletMain(&m1, 'Z');
    assert(m1.nb_chevalet_restants == NB_CHEVALET_INITIAL_MAIN);

    retirerChevaletMain(&m1, m1.chevalets[0]);
    assert(m1.nb_chevalet_restants == NB_CHEVALET_INITIAL_MAIN - 1);

    ajouterChevaletMain(&m1, 'Z');

    while (m1.nb_chevalet_restants > 0)
    {
        retirerChevaletMain(&m1, m1.chevalets[0]);
    }
    assert(m1.nb_chevalet_restants == 0);

    ajouterChevaletMain(&m2, 'A');
    ajouterChevaletMain(&m2, 'B');
    ajouterChevaletMain(&m2, 'C');
    assert(m2.nb_chevalet_restants == NB_CHEVALET_INITIAL_MAIN);

    while (m1.nb_chevalet_restants < NB_CHEVALET_INITIAL_MAIN)
    {
        ajouterChevaletMain(&m1, 'A');
    }
    assert(m1.nb_chevalet_restants == NB_CHEVALET_INITIAL_MAIN);
    ajouterChevaletPaquet(&paquet, 'A');
    assert(paquet.nb_chevalet_restants == MAX_NB_CHEVALET_PAQUET - 2 * NB_CHEVALET_INITIAL_MAIN + 1);
}