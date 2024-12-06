#pragma once

#include "main.h"
#include "partie.h"

enum
{
    NB_JOUEUR = 2
};

typedef struct
{
    Main main;
} Joueur;

/**
 * @brief Initialise un joueur
 *
 * @param j Joueur qui sera initialisé
 */
void initJoueur(Joueur *j, Partie *p);
