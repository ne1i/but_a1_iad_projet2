#include <stdio.h>

#include "headers/utils.h"

void nettoyer_stdin()
{
    int c = getchar();
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}