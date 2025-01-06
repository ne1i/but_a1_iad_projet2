#include <string.h>
#include <stdio.h>

#include "headers/joueur.h"
#include "headers/utils.h"
#include "headers/partie.h"

void initJoueur(Joueur *j, Main m)
{
    j->main = m;
}

void joueurPoseDepart(Joueur *j, MotPoses *mot_poses, Rail *rail, FILE *f, int numero_joueur)
{
    Chevalet mot[TAILLE_PREMIER_MOT + 1] = {0};
    while (!mainContientChaine(&j->main, mot) || !verifierMotDepart(mot, f, mot_poses))
    {
        printf("%d> ", numero_joueur);
        scanf("%5s", mot);
        nettoyer_stdin();
    }

    for (int i = 0; i < strlen(mot); ++i)
    {
        retirerChevaletMain(&j->main, mot[i]);
    }
    ajouterMot(mot_poses, mot);
}

void joueurPose(Joueur *j, MotPoses *mot_poses, Rail *rail, FILE *f, int numero_joueur)
{
    Coup c = {0};
    Chevalet chaine[TAILLE_MAX_COUP];
    while (!verifierCoup(&c, &j->main, rail, f, mot_poses))
    {
        printf("%d> ", numero_joueur);
        scanf("%c", &c.recto_verso);
        scanf("%11s", chaine);
        chaine[TAILLE_MAX_COUP - 1] = 0; // le dernier caractère doit être un \0 pour bien le manipuler plus tard
        nettoyer_stdin();
        repartirCoup(&c, chaine);
    }
    ajouterMot(mot_poses, c.mot);

    for (int i = 0; i < strlen(c.mot); ++i)
    {
        retirerChevaletMain(&j->main, c.mot[i]);
    }
}

void repartirCoup(Coup *c, char *chaine)
{
    int len = strlen(chaine);
    int ind_debut_mot_main = 0;
    int ind_fin_mot_main = 0;
    if (chaine[0] == '(')
    {
        for (int i = 0; chaine[i + 1] != ')'; ++i)
        {
            c->partie_rail[i] = chaine[i + 1];
        }
        ind_debut_mot_main = strlen(c->partie_rail) + 2 - 1; // la longueur de la chaine entre parenthèses + les 2 parenthèses - 1 car c'est un indice
        ind_fin_mot_main = len - 1;

        for (int i = ind_debut_mot_main + 1; i <= ind_fin_mot_main; ++i)
        {
            c->partie_main[i - ind_debut_mot_main - 1] = chaine[i];
        }
        char temp[NB_CHEVALET_RAIL + 1] = {0};
        strcpy(temp, c->partie_rail);                          // on sait que la partie rail est au début de la chaine donc on l'ajoute en premier
        strcpy(&temp[strlen(c->partie_rail)], c->partie_main); // puis on concatène la partie qui vient de la main du joueur
        strcpy(c->mot, temp);
        c->gauche_droite = 'G';
    }

    if (chaine[len - 1] == ')')
    {
        for (int i = len - 1, j = 0; chaine[i - 1] != '('; --i, ++j)
        {
            c->partie_rail[j] = chaine[i - 1];
        }
        char *partie_rail_inversee = inverseStr(c->partie_rail); // on doit l'inverser car on remplit c->partie_rail à l'envers
        strcpy(c->partie_rail, partie_rail_inversee);
        free(partie_rail_inversee);

        ind_debut_mot_main = 0;
        ind_fin_mot_main = len - strlen(c->partie_rail) - 2 - 1;
        for (int i = ind_debut_mot_main; i <= ind_fin_mot_main; ++i)
        {
            c->partie_main[i - ind_debut_mot_main] = chaine[i];
        }
        char temp[TAILLE_MAX_COUP * 2] = {0};
        strcpy(temp, c->partie_main);                          // puis on concatène la partie qui vient du rail
        strcpy(&temp[strlen(c->partie_main)], c->partie_rail); // on sait que la partie main est au début de la chaine donc on l'ajoute en premier
        strcpy(c->mot, temp);
        c->gauche_droite = 'D';
    }
}