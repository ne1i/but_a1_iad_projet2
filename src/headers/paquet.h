typedef char Chevalet;

enum
{
    NB_CHEVALET = 88
};

typedef struct
{
    Chevalet chevalets[NB_CHEVALET];
    int nb_chevalet;

} Paquet;

/**
 * @brief Initialise un paquet
 * 
 * @param p Paquet qui sera initialisé
 */
void initPaquet(Paquet p);