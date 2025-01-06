#pragma once

#include <stdlib.h>

enum
{
    NB_CARACTERES_ASCII = 128
};

typedef struct
{
    int nb_elements;
    int capacite;
    char **tab_mots;
} MotPoses;

/**
 * @brief Supprime le contenu du fichier stdin
 *
 */
void nettoyer_stdin();

/**
 * @brief Initialise un élément du type MotPoses
 *
 * @param mot_poses élément initialisé
 * @param capacite capacité initiale
 */
void initMotPoses(MotPoses *mot_poses, int capacite);

/**
 * @brief Redimensionne un élément du type MotPoses
 *
 * @param mot_poses élément initialisé
 * @param nvlCapacite capacité allouée a mot_poses
 * @return int
 */
int redimensionnerMotPoses(MotPoses *mot_poses, int nvlCapacite);

/**
 * @brief Ajoute un mot à un élément de type MotPoses
 *
 * @param mot_poses
 * @param mot
 * @return int
 */
int ajouterMot(MotPoses *mot_poses, const char *mot);

/**
 * @brief Renvoie la string s inversée mais ne la modifie pas
 *
 * @param s string qui sera inversée
 */
char *inverseStr(char *s);

/**
 * @brief Compare deux caractères a et b, renvoie un nombre positif si a est plus petit que b, un nombre négatif si b est plus petit que a, 0 si ils sont égaux
 *
 * @param a caractère
 * @param b caractère
 * @return int
 */
int comparerChars(const void *a, const void *b);

/**
 * @brief Trie la chaine de caractère str
 *
 * @param str chaine de caractère
 */
void trierStr(char *str);

/**
 * @brief Supprime un caractère d'une chaine à un indice donné et décale tout les éléments en conséquence
 *
 * @param str chaine de caractère
 * @param i indice du caractère à supprimer
 */
void supprimerChar(char *str, int i);