#pragma once

#include "main.h"

typedef struct
{
    Main main;
} Joueur;

/**
 * @brief Initialise un joueur
 *
 * @param j Joueur qui sera initialisé
 */
void initJoueur(Joueur *j, Main m);

void joueurPose(Joueur *j, const char *mot);
