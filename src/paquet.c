#include <stdio.h>
#include <string.h>

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
}