#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "headers/utils.h"
#include "headers/partie.h"
#include "headers/dictionnaire.h"
#include "headers/paquet.h"

void initPartie(Partie *p)
{
    Paquet *paq = &p->paquet;
    initPaquet(paq);

    Main m1 = {0};
    Main m2 = {0};
    initMain(&m1, paq);
    initMain(&m2, paq);

    Joueur *j1 = &p->tab_joueurs[0];
    Joueur *j2 = &p->tab_joueurs[1];
    initJoueur(j1, m1);
    initJoueur(j2, m2);

    Rail *rail = &p->rail;
    initRail(rail);
}

void boucleDeJeu(Partie *p, FILE *f, MotPoses *mot_poses)
{
    int nb_joueur_courant = 1;
    Joueur *j1 = &p->tab_joueurs[0];
    Joueur *j2 = &p->tab_joueurs[1];
    Joueur *joueur_courant = j1;
    Joueur *joueur_non_courant = j2;
    Joueur *temp = 0;
    Partie partie_tour_precedent = {0};
    printf("1 : ");
    afficherMain(&j1->main);
    printf("2 : ");
    afficherMain(&j2->main);
    printf("\n");

    joueurPoseDepart(j1, mot_poses, &p->rail, f, 1);
    joueurPoseDepart(j2, mot_poses, &p->rail, f, 2);
    printf("\n");
    remplirRail(&p->rail, mot_poses->tab_mots[0], mot_poses->tab_mots[1]);
    if (strcmp(mot_poses->tab_mots[0], mot_poses->tab_mots[1]) < 0) // le joueur ayant posé le plus petit mot joue en premier
    {
        nb_joueur_courant = 1;
        joueur_courant = j1;
        joueur_non_courant = j2;
    }

    else
    {
        nb_joueur_courant = 2;
        joueur_courant = j2;
        joueur_non_courant = j1;
    }

    afficherEtatPartie(p);
    while (j1->main.nb_chevalet_restants != 0 && j2->main.nb_chevalet_restants != 0)
    {
        j1->a_fait_signalement = 0;
        j2->a_fait_signalement = 0;
        joueurJoue(p, &partie_tour_precedent, mot_poses, f, nb_joueur_courant);
        if (joueur_courant == j1)
        {
            joueur_courant = j2;
            joueur_non_courant = j1;
            nb_joueur_courant = 2;
        }
        else
        {
            joueur_courant = j1;
            joueur_non_courant = j2;
            nb_joueur_courant = 1;
        }
        // partie_tour_precedent = *p;
    }
}

int verifierMotDepart(const char *mot, FILE *f, const MotPoses *mot_poses)
{
    if (strlen(mot) != TAILLE_PREMIER_MOT)
    {
        return 0;
    }

    if (motDejaPose(mot_poses, mot))
    {
        return 0;
    }

    if (!dictionnaireContient(mot, f))
    {
        return 0;
    }

    return 1;
}

int verifierMot(const char *mot, FILE *f, const MotPoses *mot_poses)
{
    if (strlen(mot) > NB_CHEVALET_RAIL)
    {
        return 0;
    }

    if (motDejaPose(mot_poses, mot))
    {
        return 0;
    }

    if (!dictionnaireContient(mot, f))
    {
        return 0;
    }
    return 1;
}

int motDejaPose(const MotPoses *mot_poses, const char *mot)
{
    for (int i = 0; i < mot_poses->nb_elements; ++i)
    {
        if (strcmp(mot_poses->tab_mots[i], mot) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void afficherEtatPartie(Partie *p)
{
    if (p->tab_joueurs[0].main.nb_chevalet_restants != 0 && p->tab_joueurs[1].main.nb_chevalet_restants != 0)
    {
        printf("1 : ");
        afficherMain(&p->tab_joueurs[0].main);
        printf("2 : ");
        afficherMain(&p->tab_joueurs[1].main);
        afficherRail(&p->rail);
        printf("\n");
    }
}

int verifierCoup(const Coup *c, const Main *m, const Rail *rail, FILE *f, const MotPoses *mot_poses)
{
    if (strlen(c->partie_main) == 0)
    {
        return 0;
    }

    if (!mainContientChaine(m, c->partie_main))
    {
        return 0;
    }

    if (!railContient(rail, c->partie_rail, c->recto_verso, c->gauche_droite))
    {
        return 0;
    }

    if (!verifierMot(c->mot, f, mot_poses))
    {
        return 0;
    }

    return 1;
}

void joueurJoue(Partie *partie, Partie *ptp, MotPoses *mot_poses, FILE *f, int numero_joueur_actif)
{
    int numero_joueur_inactif = numero_joueur_actif == 1 ? 2 : 1;
    int erreur = 1;
    Joueur *j_actif = numero_joueur_actif == 1 ? &partie->tab_joueurs[0] : &partie->tab_joueurs[1];
    Joueur *j_actif_tour_precedent = numero_joueur_actif == 1 ? &ptp->tab_joueurs[1] : &ptp->tab_joueurs[0]; // si le joueur actif du tour actuel est le joueur 1, alors le joueur actif du tour d'avant est le joueur 2

    Joueur *j_inactif = numero_joueur_actif == 1 ? &partie->tab_joueurs[1] : &partie->tab_joueurs[0];
    Joueur *j_inactif_tour_precedent = numero_joueur_actif == 1 ? &ptp->tab_joueurs[1] : &ptp->tab_joueurs[0];

    Paquet *p = &partie->paquet;
    Rail *rail = &partie->rail;
    char intention = 0;                                 // R, V ou -
    Chevalet chevalet_a_echanger[TAILLE_MAX_MOT] = {0}; // 2 pour s'assurer que l'utilisateur rentre 1 seul caractère lors de la pioche
    Coup c = {0};
    Chevalet chaine[TAILLE_MAX_COUP];
    while (!verifierCoup(&c, &j_actif->main, rail, f, mot_poses))
    {
        erreur = 1;
        memset(&c, 0, sizeof(Coup));
        printf("%d> ", numero_joueur_actif);
        scanf("%c", &intention);

        if (intention == '\n')
        {
            continue;
        }
        if (intention == ' ')
        {
            nettoyer_stdin();
            continue;
        }

        if (intention == '-')
        {
            scanf("%29s", &chevalet_a_echanger);
            nettoyer_stdin();
            chevalet_a_echanger[TAILLE_MAX_MOT - 1] = 0;
            if (chevaletAEchangerCorrect(&j_actif->main, chevalet_a_echanger))
            {
                piocher(&j_actif->main, p, chevalet_a_echanger);

                printf("\n");
                afficherEtatPartie(partie);
                return;
            }
            erreur = 0;
            continue;
        }

        if ((intention == 'r' || intention == 'v') && !j_actif->a_fait_signalement)
        {
            scanf("%11s", chaine);
            nettoyer_stdin();
            c.recto_verso = toupper(intention); // pour passer de r à R et de v à V
            chaine[TAILLE_MAX_COUP - 1] = 0;    // le dernier caractère doit être un \0 pour bien le manipuler plus tard
            repartirCoup(&c, chaine);
            if (signalementCorrect(partie, ptp, mot_poses, f, numero_joueur_inactif, &c))
            {
                printf("\n");
                while (!chevaletAEchangerCorrect(&j_actif->main, chevalet_a_echanger))
                {
                    printf("-%d> ", numero_joueur_actif);
                    scanf("%29s", chevalet_a_echanger);
                    nettoyer_stdin();
                }
                retirerChevaletMain(&j_actif->main, chevalet_a_echanger[0]);
                printf("\n");
                afficherEtatPartie(partie);
                return;
            }
            memset(&c, 0, sizeof(Coup));
            j_actif->a_fait_signalement = 1;
            erreur = 0;
            continue;
        }

        if (intention == 'R' || intention == 'V')
        {
            ptp->tab_joueurs[0] = partie->tab_joueurs[0]; // sauvegarde du statut
            ptp->tab_joueurs[1] = partie->tab_joueurs[1]; // sauvegarde du statut
            ptp->rail = *rail;                            // sauvegarde du statut

            scanf("%11s", chaine);
            nettoyer_stdin();
            c.recto_verso = intention;
            chaine[TAILLE_MAX_COUP - 1] = 0; // le dernier caractère doit être un \0 pour bien le manipuler plus tard
            repartirCoup(&c, chaine);
            erreur = 0;
        }

        if (erreur)
        {
            nettoyer_stdin();
        }
    }
    ajouterMot(mot_poses, c.mot);
    Chevalet *chevalets_ejectes = ejecterRail(rail, c.partie_main, c.recto_verso, c.gauche_droite);
    ajouterMain(&j_inactif->main, chevalets_ejectes);
    free(chevalets_ejectes);

    for (int i = 0; i < strlen(c.partie_main); ++i)
    {
        retirerChevaletMain(&j_actif->main, c.partie_main[i]);
    }
    printf("\n");
    afficherEtatPartie(partie);
    if (strlen(mot_poses->tab_mots[mot_poses->nb_elements - 1]) == NB_CHEVALET_RAIL)
    {
        while (!chevaletAEchangerCorrect(&j_actif->main, chevalet_a_echanger))
        {
            printf("-%d> ", numero_joueur_actif);
            scanf("%29s", chevalet_a_echanger);
            nettoyer_stdin();
        }
        retirerChevaletMain(&j_actif->main, chevalet_a_echanger[0]);
        printf("\n");
        afficherEtatPartie(partie);
    }
}

int signalementCorrect(const Partie *partie, const Partie *ptp, const MotPoses *mot_poses, FILE *f, int numero_joueur_inactif, const Coup *c)
{
    const Joueur *j_inactif = numero_joueur_inactif == 1 ? &partie->tab_joueurs[0] : &partie->tab_joueurs[1];
    const Joueur *j_inactif_tour_precedent = numero_joueur_inactif == 1 ? &ptp->tab_joueurs[0] : &ptp->tab_joueurs[1];
    const Joueur *j_actif = numero_joueur_inactif == 1 ? &partie->tab_joueurs[1] : &partie->tab_joueurs[0];

    if (j_actif->a_fait_signalement)
    {
        return 0;
    }

    if (j_inactif->main.nb_chevalet_restants == j_inactif_tour_precedent->main.nb_chevalet_restants) // si le joueur a le même nombre de chevalet, alors il n'a pas joué de mot
    {
        return 0;
    }

    if (!railContient(&ptp->rail, c->partie_rail, c->recto_verso, c->gauche_droite))
    {
        return 0;
    }

    if (!verifierCoup(c, &j_inactif_tour_precedent->main, &ptp->rail, f, mot_poses))
    {
        return 0;
    }

    if (strlen(mot_poses->tab_mots[mot_poses->nb_elements - 1]) == NB_CHEVALET_RAIL)
    {
        return 0;
    }

    return 1;
}