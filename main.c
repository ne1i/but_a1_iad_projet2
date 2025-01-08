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
    trierStr(m->chevalets);
}

void afficherMain(const Main *m)
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

void ajouterMain(Main *m, Chevalet *chaine)
{
    strcpy(&m->chevalets[m->nb_chevalet_restants], chaine);
    trierStr(m->chevalets);
    m->nb_chevalet_restants += strlen(chaine);
}

void ajouterChevaletMain(Main *m, Chevalet c)
{
    m->chevalets[m->nb_chevalet_restants] = c;
    trierStr(m->chevalets);
    m->nb_chevalet_restants++;
}

void piocher(Main *m, Paquet *p, Chevalet c)
{
    if (!mainContientChaine(m, &c))
    {
        return;
    }
    retirerChevaletMain(m, c);
    Chevalet c_pioche = p->chevalets[p->nb_chevalet_restants - 1];
    p->chevalets[p->nb_chevalet_restants - 1] = 0;
    p->nb_chevalet_restants--;
    ajouterChevaletMain(m, c_pioche);
}

int chevaletAEchangerCorrect(const Main *m, Chevalet c)
{
    if (c < 'A' || c > 'Z')
    {
        return 0;
    }

    if (!mainContientChaine(m, &c))
    {
        return 0;
    }
    return 1;
}