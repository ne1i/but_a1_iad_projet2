#pragma once

#include "joueur.h"
#include "rail.h"

enum
{
    TAILLE_PREMIER_MOT = 4
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
 */
void boucleDeJeu(Partie *p);

/**
 * @brief Vérifie si le mot saisi est valide (sa longueur est de 4 lettres et il est pas dans le dictionnaire
 * ou les lettres détenues par le joueur ne sont pas suffisantes)
 *
 * @param mot
 */
int verifierMot(const char *mot);
