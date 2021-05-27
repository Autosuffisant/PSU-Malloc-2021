/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** Recreate standard allocation functions
*/

#include "memory_block.h"

static mem_block_t starting_block = NULL;

mem_block_t extend_heap(mem_block_t block, size_t block_size)
{
    mem_block_t new;
    new = sbrk(0);
    if (sbrk(block_size) == (void *)-1)
        return NULL;
    new->size = block_size;
    new->next = NULL;
    if (block)
        block->next = new;
    new->free = 0;
    return new;
}

void split_free_block(mem_block_t block, size_t block_size)
{
    mem_block_t new_block = NULL;

    new_block->size = block->size - block_size;
    new_block->next = block->next;
    new_block->free = 1;
    block->size = block_size;
    block->next = new_block;
}

mem_block_t best_fit(mem_block_t *first, size_t block_size)
{
    mem_block_t s = *first;
    size_t smallest = s->size;

    while (s) {
        if (s->size == block_size)
            return s;
        if (s->size < smallest && s->size > block_size)
            smallest = s->size;
        s = s->next;
    }
    best_fit(first, smallest);
    return NULL;
}

mem_block_t create_new_block(mem_block_t free_block, size_t alloced_size)
{
    mem_block_t new;

    new = starting_block;
    free_block = best_fit(&new, alloced_size);
    if (free_block) {
        if (free_block->size - alloced_size >= (getpagesize() * 2)
        + sizeof(mem_block_t))
            split_free_block(free_block, alloced_size);
        free_block->free = 0;
    } else {
        free_block = extend_heap(new, alloced_size);
        if (!free_block)
            return NULL;
    }
    return free_block;
}

void *malloc(size_t size)
{
    size_t alloced_size;
    mem_block_t free_block = 0;

    alloced_size = align_break(closest_pwr_two(size));
    if (starting_block) {
        free_block = create_new_block(free_block, alloced_size);
    } else {
        free_block = extend_heap(NULL, alloced_size);
        if (!free_block)
            return NULL;
        starting_block = free_block;
    }
    return free_block->data;
}