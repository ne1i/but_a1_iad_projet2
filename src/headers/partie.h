#pragma once

#include "joueur.h"


typedef struct
{
    Joueur *tab_joueurs[NB_JOUEUR];
    Paquet paquet;
} Partie;