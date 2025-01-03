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
 * @param mot_poses Liste des mots joués
 * @param rail Rail de la partie
 * @param f Dictionnaire de la partie
 * @param numero_joueur Numero du joueur (1 ou 2)
 */
void joueurPose(Joueur *j, MotPoses *mot_poses, Rail *rail, FILE *f, int numero_joueur);
