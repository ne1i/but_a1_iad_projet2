#pragma once

typedef char Chevalet;

/**
 * @brief Définit le nombre de chevalet dans le paquet
 *
 */
enum
{
    MAX_NB_CHEVALET_PAQUET = 88
};

/**
 * @brief Définit le nombre de lettre différentes dans le paquet
 *
 */
enum
{
    NB_LETTRES = 21
};

/**
 * @brief Représente un paquet de chevalets (donc la pioche)
 *
 */
typedef struct
{
    Chevalet chevalets[MAX_NB_CHEVALET_PAQUET];
    int nb_chevalet_restants;
} Paquet;

/**
 * @brief Initialise un paquet
 *
 * @param p Paquet qui sera initialisé
 */
void initPaquet(Paquet *p);
/**
 * @brief Melange un paquet
 *
 * @param p Paquet qui sera mélangé
 */
void melangePaquet(Paquet *p);