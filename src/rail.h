#pragma once

#include "paquet.h"

/**
 * @brief Nombre de chevalet dans le rail
 *
 */
enum
{
    NB_CHEVALET_RAIL = 8
};

/**
 * @brief Rail de la partie
 *
 */
typedef struct
{
    Chevalet chevalets_recto[NB_CHEVALET_RAIL + 1];
    Chevalet chevalets_verso[NB_CHEVALET_RAIL + 1];

} Rail;

/**
 * @brief Initialise un rail
 *
 * @param rail Rail qui sera initialisé
 */
void initRail(Rail *rail);

/**
 * @brief Affiche les chevalets présents sur le rail (recto et verso)
 *
 * @param rail Rail qui sera affiché
 */
void afficherRail(const Rail *rail);

/**
 * @brief Remplis le rail avec les 2 mots de 4 lettres dans l'ordre alphabétique
 *
 * @param rail Rail qui sera rempli
 * @param mot1 Mot qui sera ajouté au rail
 * @param mot2 Mot qui sera ajouté au rail
 */
void remplirRail(Rail *rail, const char *mot1, const char *mot2);

/**
 * @brief Renvoie 1 si le rail contient la chaine exacte, 0 sinon
 *
 * @param rail rail
 * @param chaine chaine
 * @param recto_verso 'R' ou 'V'
 * @param gauche_droite 'G' ou 'D'
 * @return int
 */
int railContient(const Rail *rail, const Chevalet *chaine, const char recto_verso, const char gauche_droite);

/**
 * @brief Ejecte la chaine de caractère du rail et renvoie la chaine de caractère éjectée (il faut la free par la suite, sinon fuite de mémoire)
 *
 * @param rail rail
 * @param chaine chaine de caractère
 * @param recto_verso 'R' ou 'V'
 * @param gauche_droite 'G' ou 'D'
 */
Chevalet *ejecterRail(Rail *rail, Chevalet *chaine, char recto_verso, char gauche_droite);