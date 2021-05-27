/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** Recreate standard allocation functions
*/

#include "memory_block.h"

size_t closest_pwr_two(size_t size)
{
    size_t i = 1;

    size = size + sizeof(mem_block_t);
    while (i < size)
        i *= 2;
    return i;
}

size_t align_break(size_t size)
{
    unsigned int alignment = (int)getpagesize() * 2;
    unsigned int aligned_size = alignment;

    while (size > aligned_size)
        aligned_size += alignment;
    return aligned_size;
}