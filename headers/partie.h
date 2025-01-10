#pragma once

#include "joueur.h"
#include "rail.h"
#include "utils.h"

/**
 * @brief Nombre de joueur d ans une partie
 *
 */
enum
{
    NB_JOUEUR = 2
};

/**
 * @brief Taille des deux premiers mots d'une partie
 *
 */
enum
{
    TAILLE_PREMIER_MOT = 4
};

/**
 * @brief  Taille maximale d'un mot
 *
 */
enum
{
    TAILLE_MAX_MOT = 29
};

/**
 * @brief Partie du jeu Octo Verso
 *
 */
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
 * @brief Vérifie si le mot saisi est valide (sa longueur est de moins de 8 lettres et il est présent dans le dictionnaire
 * et les lettres détenues par le joueur sont suffisantes et il n'a pas déjà été posé)
 *
 * @param mot Mot à vérifier
 * @param f Dictionnaire utilisé
 * @param mot_poses Liste des mots déjà posés
 */
int verifierMot(const char *mot, FILE *f, const MotPoses *mot_poses);

/**
 * @brief Vérifie si le mot saisi est valide (sa longueur est de 4 lettres et il est dans le dictionnaire
 * et les lettres détenues par le joueur sont suffisantes et il n'a pas déjà été posé)
 *
 * @param mot Mot à vérifier
 * @param f Dictionnaire utilisé
 * @param mot_poses Liste des mots posés
 */
int verifierMotDepart(const char *mot, FILE *f, const MotPoses *mot_poses);

/**
 * @brief Renvoie 1 si un mot a déjà été joué dans la partie, renvoie 0 sinon
 *
 * @param mot_poses Tableau dynamique des mots posés
 * @param mot mot a vérifier
 * @return int
 */
int motDejaPose(const MotPoses *mot_poses, const char *mot);

/**
 * @brief Affiche l'état actuel de la partie (main des joueurs et rail)
 *
 * @param p Partie à afficher
 */
void afficherEtatPartie(Partie *p);

/**
 * @brief Renvoie 1 si le coup est jouable, 0 sinon
 *
 * @param c Coup joué
 * @param m Main du jour qui fait le coup
 * @param rail Rail de la partie
 * @param f Dictionnaire
 * @param mot_poses Liste des mots posés
 * @return int
 */
int verifierCoup(const Coup *c, const Main *m, const Rail *rail, FILE *f, const MotPoses *mot_poses);

/**
 * @brief Gère l'action d'un joueur dans un tour et renvoie 1 si le joueur a fait un signalement correct, 0 sinon
 *
 * @param partie Partie actuelle
 * @param partie_tour_precedent Partie du tour précédent
 * @param mot_poses Tableau des mots posés
 * @param f Dictionnaire
 * @param numero_joueur_actif Numéro du joueur actif
 * @return int
 */
int joueurJoue(Partie *partie, Partie *partie_tour_precedent, MotPoses *mot_poses, FILE *f, int numero_joueur_actif);

/**
 * @brief Renvoie 1 si le signalement désigné par les paramètres est correct, 0 sinon
 *
 * @param partie Partie en cours
 * @param ptp Partie du tour d'avant
 * @param mot_poses Liste des mots posés
 * @param f Dictionnaire
 * @param numero_joueur_inactif Numero du joueur qui ne joue pas ce tour ci
 * @param c Coup du signalement
 * @return int
 */
int signalementCorrect(const Partie *partie, const Partie *ptp, const MotPoses *mot_poses, FILE *f, int numero_joueur_inactif, const Coup *c);