/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** Recreate standard allocation functions
*/

#include "memory_block.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t *new;

    if (nmemb == 0 || size == 0)
        return NULL;
    new = malloc(nmemb * size);
    if (new) {
        for (unsigned int i = 0; i != nmemb; i++)
            new[i] = 0;
    } else
        return NULL;
    return new;
}