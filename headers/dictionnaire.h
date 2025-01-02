#pragma once
#include <stdlib.h>

#define DICT_FILE_NAME "ods4.txt"

/**
 * @brief Renvoie 1 si le dictionnaire contient le mot, 0 sinon
 *
 * @param mot Le mot qui sera cherché dans le dictionnaire
 * @return int
 */
int dictionnaireContient(const char *mot, FILE *f);
