#include <string.h>
#include <stdio.h>

#include "headers/joueur.h"
#include "headers/utils.h"
#include "headers/partie.h"

void initJoueur(Joueur *j, Main m)
{
    j->main = m;
}

void joueurPose(Joueur *j, MotPoses *mot_poses, Rail *rail, FILE *f, int numero_joueur)
{
    Chevalet motJ1[TAILLE_PREMIER_MOT + 1] = {0};
    while (!mainContientChaine(&j->main, motJ1) || !verifierMotDepart(motJ1, f, mot_poses))
    {
        printf("%d> ", numero_joueur);
        scanf("%5s", motJ1);
        nettoyer_stdin();
    }

    for (int i = 0; i < strlen(motJ1); ++i)
    {
        retirerChevaletMain(&j->main, motJ1[i]);
    }
    ajouterMot(mot_poses, motJ1);
}