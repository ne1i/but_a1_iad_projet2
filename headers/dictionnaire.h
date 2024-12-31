#pragma once
#include <stdlib.h>

#define DICT_FILE_NAME "ods4.txt"

enum
{
    TAILLE_MAX_MOT = 29
};

/**
 * @brief Renvoie 1 si le dictionnaire contient le mot, 0 sinon
 *
 * @param mot Le mot qui sera cherché dans le dictionnaire
 * @return int
 */
int dictionnaire_contient(const char *mot, FILE *f);
