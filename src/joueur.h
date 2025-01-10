#pragma once
#include <stdio.h>

#include "main.h"
#include "rail.h"
#include "utils.h"

/**
 * @brief Nombre de caractère maximum dans un coup
 *
 */
enum
{
    TAILLE_MAX_COUP = 11
};

/**
 * @brief Joueur de la partie
 *
 */
typedef struct
{
    Main main;
    int a_fait_signalement;
} Joueur;

/**
 * @brief Coup qu'un joueur fait une fois le départ fini
 *
 */
typedef struct
{
    char recto_verso;
    char gauche_droite;
    Chevalet partie_rail[TAILLE_MAX_COUP];
    Chevalet partie_main[TAILLE_MAX_COUP];
    Chevalet mot[NB_CHEVALET_RAIL + 1];
} Coup;

/**
 * @brief Initialise un joueur
 *
 * @param j Joueur qui sera initialisé
 * @param m Main qui lui sera donnée
 */
void initJoueur(Joueur *j, Main m);

/**
 * @brief Retire les chevalets qui composent le mot de la main du joueur et les place dans le rail (uniquement pour les 2 premiers coups)
 *
 * @param j Joueur affecté
 * @param mot_poses Liste des mots joués
 * @param rail Rail de la partie
 * @param f Dictionnaire de la partie
 * @param numero_joueur Numero du joueur (1 ou 2)
 */
void joueurPoseDepart(Joueur *j, MotPoses *mot_poses, Rail *rail, FILE *f, int numero_joueur);

/**
 * @brief Répartit le contenu de mot dans c
 *
 * @param c
 * @param mot
 */
void repartirCoup(Coup *c, char *mot);