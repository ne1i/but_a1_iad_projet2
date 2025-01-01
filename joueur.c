#include <string.h>

#include "headers/joueur.h"

void initJoueur(Joueur *j, Main m)
{
    j->main = m;
}

void joueurPose(Joueur *j, const char *mot)
{
    for (int i = 0; i < strlen(mot); ++i)
    {
        retirerChevaletMain(&j->main, mot[i]);
    }
}