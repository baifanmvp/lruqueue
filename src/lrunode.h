#include "lrudef.h"
typedef struct st_lru_node
{
    //data info
    uint64_t key; //first locatuon for lruhash module
    void* data;

    //node info
    uint32_t id;
    struct st_lru_node* prev;
    struct st_lru_node* next;
}lru_node;

#define LRUNODE_ALLOC(pnode)  (pnode=(lru_node*)calloc(1, sizeof(lru_node));)

#define LRUNODE_FREE(pnode)  (free(pnode);)

#define LRUNODE_NEXT(pnode)  ((pnode)->next)

#define LRUNODE_PREV(pnode)  ((pnode)->prev)

#define LRUNODE_DATA(pnode)  ((pnode)->data)

#define LRUNODE_ID(pnode)  ((pnode)->id)

#define LRUNODE_KEY(pnode)  ((pnode)->key)

#define LRUNODE_LOAD(pnode, id, data)  ((pnode)->nodeno=id;(pnode)->data=data;)
