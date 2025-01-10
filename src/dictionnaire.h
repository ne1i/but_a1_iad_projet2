#pragma once

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Renvoie 1 si le dictionnaire contient le mot, 0 sinon
 *
 * @param mot Le mot qui sera cherché dans le dictionnaire
 * @param f Dictionnaire
 * @return int
 */
int dictionnaireContient(const char *mot, FILE *f);
