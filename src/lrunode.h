#include "lrudef.h"
typedef struct st_lru_node
{
    uint64_t nodeno;
    void* data;
    struct st_lru_node* prev;
    struct st_lru_node* next;
}lru_node;

#define LRUNODE_ALLOC(pnode)  (pnode=(lru_node*)calloc(1, sizeof(lru_node));)

#define LRUNODE_FREE(pnode)  (free(pnode);)

#define LRUNODE_NEXT(pnode)  ((pnode)->next)

#define LRUNODE_PREV(pnode)  ((pnode)->prev)

#define LRUNODE_DATA(pnode)  ((pnode)->data)

#define LRUNODE_NO(pnode)  ((pnode)->nodeno)

#define LRUNODE_LOAD(pnode, no, data)  ((pnode)->nodeno=no;(pnode)->data=data;)
