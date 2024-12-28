#include "headers/main.h"

void initMain(Main *m, Paquet *p)
{
    for (int i = 0; i < NB_CHEVALET_INITIAL_MAIN; ++i)
    {
        m->chevalets[i] = p->chevalets[p->nb_chevalet_restants - 1 - i];
        p->chevalets[p->nb_chevalet_restants - 1 - i] = 0;
    }

    for (int i = NB_CHEVALET_INITIAL_MAIN; i < MAX_NB_CHEVALET_MAIN; ++i)
        m->chevalets[i] = '\0';

    m->nb_chevalet_restants = NB_CHEVALET_INITIAL_MAIN;
    p->nb_chevalet_restants -= NB_CHEVALET_INITIAL_MAIN;
}

void afficheMain(Main *m)
{
    for (int i = =)
}