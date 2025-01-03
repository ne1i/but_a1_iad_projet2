#pragma once

#include "joueur.h"
#include "rail.h"
#include "utils.h"

enum
{
    NB_JOUEUR = 2
};

enum
{
    TAILLE_PREMIER_MOT = 4
};

enum
{
    TAILLE_MAX_MOT = 29
};

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

/**
 * @brief Execute une partie jusqu'à sa fin
 *
 * @param p Les informations de la partie
 * @param f Dictionnaire utilisé
 * @param mot_poses Liste des mots posés
 */
void boucleDeJeu(Partie *p, FILE *f, MotPoses *mot_poses);

/**
 * @brief Vérifie si le mot saisi est valide (sa longueur est de moins de 8 lettres et il est pas dans le dictionnaire
 * ou les lettres détenues par le joueur ne sont pas suffisantes ou il a déjà été posé)
 *
 * @param mot
 * @param f Dictionnaire utilisé
 * @param mot_poses Liste des mots déjà posés
 */
int verifierMot(const char *mot, FILE *f, MotPoses *mot_poses);

/**
 * @brief Vérifie si le mot saisi est valide (sa longueur est de 4 lettres et il est pas dans le dictionnaire
 * ou les lettres détenues par le joueur ne sont pas suffisantes ou il a déjà été posé)
 *
 * @param mot
 * @param f Dictionnaire utilisé
 * @param mot_poses Liste des mots posés
 */
int verifierMotDepart(const char *mot, FILE *f, MotPoses *mot_poses);

/**
 * @brief Renvoie 1 si un mot a déjà été joué dans la partie, renvoie 0 sinon
 *
 * @param mot_poses Tableau dynamique des mots posés
 * @param mot mot a vérifier
 * @return int
 */
int motDejaPose(const MotPoses *mot_poses, const char *mot);