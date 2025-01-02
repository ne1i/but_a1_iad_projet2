#include <stdio.h>
#include <string.h>

#include "headers/dictionnaire.h"
#include "headers/partie.h"

int dictionnaireContient(const char *mot, FILE *f)
{
    rewind(f);
    char mot_dico[TAILLE_MAX_MOT + 1] = {0};
    while (fscanf(f, "%29s", mot_dico) != EOF)
    {
        if (strcmp(mot_dico, mot) == 0)
        {
            return 1;
        }
    }
    return 0;
}