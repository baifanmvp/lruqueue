#include "lruhash.h"

lru_hash* lru_hash_new()
{
    lru_hash* lp_lru_hash = (lru_hash*)calloc(1, sizeof(lru_hash));
    
    lp_lru_hash->ghash = g_hash_table_new(g_int64_hash, g_int64_equal);

    return lp_lru_hash;
    
}

lbool lru_hash_delete(lru_hash* phash)
{
    if(!phash) return LRU_FALSE;
    
    g_hash_table_destroy(phash->ghash);
    
    free(phash);

    return LRU_TRUE;
}

lru_node* lru_hash_lookup(lru_hash* phash, uint64_t* key)
{
    if(!phash) return LRU_FALSE;
    return g_hash_table_lookup(phash,  key);
}

lbool lru_hash_add(lru_hash* phash, lru_node* pnode)
{
    uint64_t* phashval = (uint64_t*)pnode;
    if(lru_hash_lookup(phash, phashval))
    {
        printf("node hashval is repeat ! hash add false\n");
        return LRU_FALSE;
    }
    else
    { 
        g_hash_table_insert(phash, pnode);
        return LRU_TURE;
    }
    
}

lbool lru_hash_add_non_find(lru_hash* phash, lru_node* pnode)
{
    
    g_hash_table_insert(phash, pnode);
    return LRU_TURE;
    
}

