#pragma once

#define DICT_FILE_NAME "ods4.txt"
#include "utils.h"

#include <stdlib.h>

char **dictionnaire = 0;

int dictionnaire_contient(const char *mot);

void charger_dictionnaire();
