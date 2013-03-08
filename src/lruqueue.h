#ifndef _LRU_QUEUE_H
#define _LRU_QUEUE_H
#include "lrudef.h"
#include "lrunode.h"

typedef struct st_lru_list
{
    lru_node* head;
    lru_node* tail;
    int cnt;
}lru_list;


typedef struct st_lru_queue
{
    int t_cnt;
    lru_list* free;
    lru_list* queue;

    lru_hash* hash;
}lru_queue;
#define LRU_NODE_COUNT 1000
#define LRU_LIST_HEAD(list) ((list)->head)
#define LRU_LIST_TAIL(list) ((list)->tail->prev)
#define LRU_LIST_CNT(list) ((list)->cnt)

lru_queue* lru_queue_new(int node_cnt);

lbool lru_queue_delete(lru_queue* lp_lru_queue);

//find return non-null ,not find return null
void* lru_queue_find(lru_queue* lp_lru_queue, uint64_t hashval);


//if node has been exist,return the node
void* lru_queue_update(lru_queue* lp_lru_queue, uint64_t hashval);

#endif
