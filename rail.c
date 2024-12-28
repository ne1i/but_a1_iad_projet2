#include "headers/rail.h"

void initRail(Rail *rail)
{
    for (int i = 0; i < NB_CHEVALET_RAIL; ++i)
        rail->chevalets_recto[i] = '\0';

    for (int i = 0; i < NB_CHEVALET_RAIL; ++i)
        rail->chevalets_verso[i] = '\0';
}