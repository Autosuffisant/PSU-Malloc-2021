/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** Recreate standard allocation functions
*/

#include "memory_block.h"

void *realloc(void *ptr, size_t size)
{
    if (!ptr)
        return malloc(size);
    free(ptr);
    ptr = malloc(size);
    return ptr;
}