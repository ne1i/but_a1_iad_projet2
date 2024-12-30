#ifndef UTILS_H
#define UTILS_H

#include <string.h>

int arr_contains(const char *arr[], const char *str)
{
    for (int i = 0; arr[i] != NULL; ++i)
    {
        if (strcmp(arr[i], str) == 0)
            return 1;
    }
    return 0;
}

void panic(const char *message)
{
    perror(message);
    exit(1);
}

#endif