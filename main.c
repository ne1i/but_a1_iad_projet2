#include <stdio.h>
#include <string.h>

#include "headers/main.h"

void initMain(Main *m, Paquet *p)
{
    for (int i = 0; i < NB_CHEVALET_INITIAL_MAIN; ++i)
    {
        int dernierIdx = p->nb_chevalet_restants - 1 - i;
        Chevalet dernier = p->chevalets[dernierIdx];
        // On se débarasse du dernier chevalet tiré
        p->chevalets[dernierIdx] = 0;

        // On place le chevalet tiré dans la main
        m->chevalets[i] = dernier;
    }

    m->nb_chevalet_restants = NB_CHEVALET_INITIAL_MAIN;
    p->nb_chevalet_restants -= NB_CHEVALET_INITIAL_MAIN;
}

void afficheMain(const Main *m)
{
    for (int i = 0; m->chevalets[i] != 0; ++i)
    {
        printf("%c", m->chevalets[i]);
    }
    printf("\n");
}

// int mainContientChaine(const Main *m, const char *chaine)
// {
// }