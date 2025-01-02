#pragma once

#include "main.h"
#include "utils.h"
#include "rail.h"

typedef struct
{
    Main main;
} Joueur;

/**
 * @brief Initialise un joueur
 *
 * @param j Joueur qui sera initialisé
 * @param m Main qui lui sera donnée
 */
void initJoueur(Joueur *j, Main m);

/**
 * @brief Retire les chevalets qui composent le mot de la main du joueur
 *
 * @param j joueur affecté
 * @param mot mot qui sera retiré de la main du joueur
 */
void joueurPose(Joueur *j, const char *mot, MotPoses *mot_poses, Rail *rail);
