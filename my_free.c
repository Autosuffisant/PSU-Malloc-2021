/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** Recreate standard allocation functions
*/

#include "memory_block.h"

mem_block_t free_block_fusion(mem_block_t freed_block)
{
    if (freed_block->next && freed_block->next->free) {
        freed_block->size += freed_block->next->size;
        freed_block->next = freed_block->next->next;
    }
    return freed_block;
}

int is_block(void *ptr)
{
    if (ptr < sbrk(0))
        return 1;
    return 0;
}

mem_block_t get_block_from_ptr(void *ptr)
{
    char *adr = ptr;
    return ptr = adr - offsetof(struct mem_block_s, data);
}

void free(void *ptr)
{
    mem_block_t freed_block = get_block_from_ptr(ptr);
    if (is_block(ptr) == 1) {
        freed_block->free = 1;
        free_block_fusion(freed_block);
    }
    return;
}