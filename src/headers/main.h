#include "paquet.h"

enum
{
    MAX_NB_CHEVALET_MAIN = 12
};

typedef struct
{
    Chevalet chevalets[MAX_NB_CHEVALET_MAIN];
    int nb_chevalet;
} Main;

/**
 * @brief Initialise une main
 *
 * @param main Main qui sera initialisée
 */
void initMain(Main main);