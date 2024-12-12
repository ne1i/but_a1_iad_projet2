#pragma once

typedef char Chevalet;

enum
{
    MAX_NB_CHEVALET_PAQUET = 88
};

enum
{
    NB_LETTRES = 21
};

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