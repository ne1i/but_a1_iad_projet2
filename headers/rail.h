#pragma once

#include "paquet.h"
enum
{
    NB_CHEVALET_RAIL = 8
};

typedef struct
{
    Chevalet chevalets_recto[NB_CHEVALET_RAIL];
    Chevalet chevalets_verso[NB_CHEVALET_RAIL];
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
 * @brief Ajoute un mot au rail sans vérification
 *
 * @param rail
 * @param mot mot qui sera ajouté
 * @param cote Côté (R pour recto ou V pour verso)
 */
void ajouterMotRail(Rail *rail, const char *mot, char cote);