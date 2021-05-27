/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** Recreate standard allocation functions
*/

#include "memory_block.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    realloc(ptr, nmemb * size);
    return NULL;
}