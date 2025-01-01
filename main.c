#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "headers/utils.h"
#include "headers/main.h"
#include "headers/dictionnaire.h"
#include "headers/partie.h"

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
    printf("%s\n", m->chevalets);
}

int mainContientChaine(const Main *m, const char *chaine)
{
    int tab_code_chaine[NB_CHEVALET_RAIL + 1] = {0};
    int tab_occurences_lettres[NB_CARACTERES_ASCII] = {0};
    for (int i = 0; m->chevalets[i] != 0; ++i)
    {
        ++tab_occurences_lettres[m->chevalets[i]];
    }

    for (int i = 0; chaine[i] != 0; ++i)
    {
        tab_code_chaine[i] = chaine[i];
        --tab_occurences_lettres[chaine[i]];
    }

    for (int i = 0; tab_code_chaine[i] != 0; ++i)
    {
        if (tab_occurences_lettres[tab_code_chaine[i]] < 0)
        {
            return 0;
        }
    }
    return 1;
}

void retirerChevaletMain(Main *m, const Chevalet c)
{
    for (int i = 0; i < m->nb_chevalet_restants; ++i)
    {
        if (m->chevalets[i] == c)
        {
            for (int j = i; j < m->nb_chevalet_restants - 1; ++j)
            {
                m->chevalets[j] = m->chevalets[j + 1];
            }
            break;
        }
    }
    --m->nb_chevalet_restants;
    m->chevalets[m->nb_chevalet_restants] = 0;
}