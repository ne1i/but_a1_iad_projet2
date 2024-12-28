#pragma once

#include "joueur.h"
#include "rail.h"

typedef struct
{
    Joueur tab_joueurs[NB_JOUEUR];
    Paquet paquet;
    Rail rail;
} Partie;

/**
 * @brief Initialise une partie
 *
 * @param p Partie qui sera initialisée
 */
void initPartie(Partie *p);
