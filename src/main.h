#pragma once

#include "paquet.h"

/**
 * @brief Nombre de chevalets maximum dans une main
 *
 */
enum
{
    MAX_NB_CHEVALET_MAIN = 16,
};

/**
 * @brief Nombre de chevalets initial dans une main
 *
 */
enum
{
    NB_CHEVALET_INITIAL_MAIN = 12
};

/**
 * @brief Main d'un joueur
 *
 */
typedef struct
{
    Chevalet chevalets[MAX_NB_CHEVALET_MAIN];
    int nb_chevalet_restants;
} Main;

/**
 * @brief Initialise une main en lui assignant des chevalets du paquet
 *
 * @param main Main qui sera initialisée
 * @param p Paquet de chevalets qui sert a distribuer les chevalets
 */
void initMain(Main *m, Paquet *p);

/**
 * @brief Affiche le contenu d'une main
 *
 * @param m Main dont le contenu sera affiché
 */
void afficherMain(const Main *m);

/**
 * @brief Renvoie 1 si la main m contient les lettre nécessaires à former la chaine, 0 sinon
 *
 * @param m Main dont on vérifie les chevalets
 * @param chaine Chaine de caractère d'au plus 8 caractères
 * @return int
 */
int mainContientChaine(const Main *m, const char *chaine);

/**
 * @brief Supprime un chevalet d'une main
 *
 * @param m Main
 * @param c Chevalet qui sera supprimé de la main
 */
void retirerChevaletMain(Main *m, const Chevalet c);

/**
 * @brief Ajoute la chaine à la main du joueur puis la trie
 *
 * @param m Main du joueur
 * @param chaine Chevalet(s) à ajouter à la main
 */
void ajouterMain(Main *m, Chevalet *chaine);

/**
 * @brief Ajoute un chevalet à une main et la trie
 *
 * @param m Main d'un joueur
 * @param c Chevalet à ajouter
 */
void ajouterChevaletMain(Main *m, Chevalet c);

/**
 * @brief Echange le chevalet c s'il est présent dans la main m avec un chevalet aléatoire
 *
 * @param m Main du joueur
 * @param p Paquet de chevalets
 * @param c Chevalet à échanger
 */
void piocher(Main *m, Paquet *p, Chevalet *c);

/**
 * @brief Renvoie 1 si le chevalet c peut être échanger selon la main m, renvoie 0 sinon
 *
 * @param m Main du joueur
 * @param c Chevalet(s) à vérifier
 * @return int
 */
int chevaletAEchangerCorrect(const Main *m, Chevalet *c);