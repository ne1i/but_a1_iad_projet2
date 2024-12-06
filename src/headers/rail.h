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