#pragma once

#include "paquet.h"
enum
{
    NB_CHEVALET_RAIL = 8
};

typedef struct
{
    Chevalet chevalets_recto[NB_CHEVALET_RAIL + 1];
    Chevalet chevalets_verso[NB_CHEVALET_RAIL + 1];

} Rail;

/**
 * @brief Initialise un rail
 *
 * @param rail rail qui sera initialisé
 */
void initRail(Rail *rail);

/**
 * @brief Affiche les chevalets présents sur le rail (recto et verso)
 *
 * @param rail rail qui sera affiché
 */
void afficherRail(const Rail *rail);

/**
 * @brief Remplis le rail avec les 2 mots de 4 lettres dans l'ordre alphabétique
 *
 * @param rail rail qui sera rempli
 * @param mot1 mot qui sera ajouté au rail
 * @param mot2 mot qui sera ajouté au rail
 */
void remplirRail(Rail *rail, const char *mot1, const char *mot2);

/**
 * @brief Ajoute un mot au rail sans vérification
 *
 * @param rail
 * @param mot mot qui sera ajouté
 * @param cote Côté (R pour recto ou V pour verso)
 */
void ajouterMotRail(Rail *rail, const char *mot, char cote);