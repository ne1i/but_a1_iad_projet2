#include <string.h>

#include "headers/rail.h"

void initRail(Rail *rail)
{
    memset(rail->chevalets_recto, 0, sizeof(rail->chevalets_recto));
    memset(rail->chevalets_verso, 0, sizeof(rail->chevalets_verso));
}