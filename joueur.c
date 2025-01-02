#include <string.h>

#include "headers/joueur.h"
#include "headers/utils.h"

void initJoueur(Joueur *j, Main m)
{
    j->main = m;
}

void joueurPose(Joueur *j, const char *mot, MotPoses *mot_poses)
{
    for (int i = 0; i < strlen(mot); ++i)
    {
        retirerChevaletMain(&j->main, mot[i]);
    }
    ajouterMot(mot_poses, mot);
}