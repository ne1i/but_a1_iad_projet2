#include <stdio.h>

enum
{
    MAX_LETTRE = 88
};

enum
{
    MAX_MAIN = 20
};

typedef struct
{
    char tabMain[MAX_MAIN];
    int nb_chevalet_main;
} Main;


typedef struct
{
    char tabLettre[MAX_LETTRE];
    int nbLettre;

} Paquet;

/**
 * @brief Fonction permettant d'initialiser un paquet de Octoverso. 
 */
void initPaquet(Paquet pack);

/**
 * @brief permet d'initialiser les main des joueurs 1 et 2.
 */
void initMain(Main main);