#ifndef _LRU_QUEUE_H
#define _LRU_QUEUE_H
#include "lrudef.h"
#include "lrunode.h"

typedef struct st_lru_queue
{
    uint64_t nodeno;
    void* data;
    struct st_lru_node* prev;
    struct st_lru_node* next;
}lru_queue;

#endif
