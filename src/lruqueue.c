#include <stdio.h>
#include "lruqueue.h"
typedef struct st_lru_queue
{
    int t_cnt;
    lru_list* free;
    lru_list* queue;

    lru_hash* hash;
}lru_queue;

lru_queue* lru_queue_new(int node_cnt)
{
    if(!node_cnt) return LRU_NULL;
    
    lru_queue* lp_lru_queue = (lru_queue*)malloc(sizeof(lru_queue));
    lp_lru_queue->t_cnt = node_cnt;
    lp_lru_queue->c_cnt = 0;
    
    lp_lru_queue->queue = (lru_list*)calloc(1, sizeof(lru_list));

    lp_lru_queue->hash = lru_hash_new();
    
        
    lru_node* lp_node =LRU_NULL;
    lru_list* queue = lp_lru_queue->queue;

    //set guard node
    LRUNODE_ALLOC(lp_node);
    LRU_LIST_HEAD(queue) = lp_node; 
    queue->tail = lp_node; 

    return lp_lru_queue;
}

lbool lru_queue_delete(lru_queue* lp_lru_queue);

//find return non-null ,not find return null
void* lru_queue_find(lru_queue* lp_lru_queue, uint64_t hashkey)
{
    if(!lp_lru_queue) return LRU_NULL;
    
    lru_node* lp_node = lru_hash_lookup(lp_lru_queue->hash, &hashkey);
    
    if(lp_node)  return lp_node->data;
    
    return LRU_NULL;
}


//if node has been exist,return the node
void* lru_queue_update(lru_queue* lp_lru_queue, uint64_t hashkey, void* data)
{
    if(!lp_lru_queue) return LRU_NULL;

    lru_list* queue = lp_lru_queue->queue;

    lru_node* lp_node = lru_hash_lookup(lp_lru_queue->hash, &hashkey);
    void* lp_old_data = LRU_NULL;
    if(lp_node)
    {
        lp_old_data = lp_node->data;
        lp_node->data = data;
    }
    else
    {

        if(lp_lru_queue->c_cnt < lp_lru_queue->t_cnt)
        {
            lp_lru_queue->c_cnt++;

            //insert hashtable
            LRUNODE_ALLOC(lp_node);
            lp_node->key = hashkey;
            lp_node->data = data;
            lru_hash_add_non_find(lp_lru_queue->hash, lp_node);

            //insert lru queue
            lp_node->next = LRU_LIST_HEAD(queue);
            LRU_LIST_HEAD(queue)->prev = lp_node;
            LRU_LIST_HEAD(queue) = lp_node;
        }
        else
        {
            // lru queue elimination node
            // 1. update tailNode's data field
            // 2. tailNode become headNode
        }
    }
    
    
}


