#pragma once

#include "paquet.h"

enum
{
    MAX_NB_CHEVALET_MAIN = 20,
    NB_CHEVALET_INITIAL_MAIN = 12
};

typedef struct
{
    Chevalet chevalets[MAX_NB_CHEVALET_MAIN];
    int nb_chevalet_restants;
} Main;

/**
 * @brief Initialise une main
 *
 * @param main Main qui sera initialisée
 */
void initMain(Main *m, Paquet *p);

/**
 * @brief Affiche le contenu d'une main
 *
 * @param m Main dont le contenu sera affiché
 */
void afficheMain(Main *m);