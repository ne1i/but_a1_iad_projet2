#pragma once

#include "paquet.h"
enum
{
    NB_CHEVALET_RAIL = 8
};

typedef struct
{
    Chevalet chevalets_recto[NB_CHEVALET_RAIL];
    Chevalet chevalets_verso[NB_CHEVALET_RAIL];
} Rail;

/**
 * @brief Initialise un rail
 *
 * @param rail rail qui sera initialisé
 */
void initRail(Rail *rail);