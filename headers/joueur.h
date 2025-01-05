#pragma once

#include "main.h"
#include "utils.h"
#include "rail.h"

enum
{
    TAILLE_MAX_COUP = 11 // 8 (taille du rail) + 2 (les 2 parenthèses) + 1 (\0)
};

typedef struct
{
    Main main;
} Joueur;

typedef struct
{
    char recto_verso;
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
 * @brief Retire les chevalets qui composent le mot de la main du joueur et les place dans le rail
 *
 * @param j Joueur affecté
 * @param mot_poses Liste des mots joués
 * @param rail Rail de la partie
 * @param f Dictionnaire de la partie
 * @param numero_joueur Numero du joueur (1 ou 2)
 */
void joueurPose(Joueur *j, MotPoses *mot_poses, Rail *rail, FILE *f, int numero_joueur);

/**
 * @brief Répartit le contenu de mot dans c
 *
 * @param c
 * @param mot
 */
void repartirCoup(Coup *c, char *mot);