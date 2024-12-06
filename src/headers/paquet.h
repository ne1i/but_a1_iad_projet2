#pragma once

typedef char Chevalet;

enum
{
    MAX_NB_CHEVALET_PAQUET = 88
};

typedef struct
{
    Chevalet chevalets[MAX_NB_CHEVALET_PAQUET];
    int nb_chevalet;
} Paquet;

/**
 * @brief Initialise un paquet
 *
 * @param p Paquet qui sera initialisé
 */
void initPaquet(Paquet *p);