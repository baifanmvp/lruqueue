#ifndef _LRU_QUEUE_H
#define _LRU_QUEUE_H
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "lrunode.h"
#include "lrudef.h"

typedef struct st_lru_hash
{
    GHashTable* ghash;     
}lru_hash;

lru_hash* lru_hash_new();

lbool lru_hash_delete(lru_hash* phash);

lru_node* lru_hash_lookup(lru_hash* phash, uint64_t* hashkey);

lbool lru_hash_add(lru_hash* phash, lru_node* pnode);


lbool lru_hash_add_non_find(lru_hash* phash, lru_node* pnode);

#endif
