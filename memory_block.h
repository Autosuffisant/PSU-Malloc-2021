/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** Recreate standard allocation functions
*/

#ifndef MYMALLOC_MBLOCK
#define MYMALLOC_MBLOCK

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

size_t closest_pwr_two(size_t size);
size_t align_break(size_t size);
int is_block(void *ptr);

void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
void free(void *ptr);

typedef struct mem_block_s *mem_block_t;

struct mem_block_s {
    mem_block_t next;
    size_t size;
    size_t free;
    char data[];
};

#endif /* !MYMALLOC_MBLOCK */
