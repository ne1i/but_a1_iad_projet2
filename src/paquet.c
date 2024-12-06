#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "headers/paquet.h"

void initPaquet(Paquet *p)
{
    char tab_lettres[NB_LETTRES + 1] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', '\0'};
    int lettres_occurences[NB_LETTRES] = {9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2};
    p->nb_chevalet = MAX_NB_CHEVALET_PAQUET;
    int ind = 0;
    for (int i = 0; i < NB_LETTRES; ++i)
    {
        for (int j = 0; j < lettres_occurences[i]; ++j)
        {
            p->chevalets[ind] = tab_lettres[i];
            ++ind;
        }
    }
    melangePaquet(p);
}

void melangePaquet(Paquet *p)
{
    char temp;
    int rand_ind;
    for (int i = MAX_NB_CHEVALET_PAQUET - 1; i >= 0; --i)
    {
        rand_ind = rand() % (i + 1);
        temp = p->chevalets[i];
        p->chevalets[i] = p->chevalets[rand_ind];
        p->chevalets[rand_ind] = temp;
    }
}