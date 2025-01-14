#include <stdio.h>

#include "partie.h"
#include "tests.h"

int main()
{
    FILE *f = fopen("ods4.txt", "r");
    if (f == NULL)
    {
        printf("fichier non accessible\n");
        return -1;
    }

    MotPoses mot_poses;
    initMotPoses(&mot_poses, 1);
    Partie p = {0};
    initPartie(&p);
    testPartie(p);
    boucleDeJeu(&p, f, &mot_poses);
    return 0;
}