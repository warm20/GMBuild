#ifndef _GMB_HASH_H_
#define _GMB_HASH_H_
#include "gmb_string.h"

typedef struct gmb_hash_item {
    gmb_string key;
    gmb_string value;
}gmb_hash_item;

typedef struct gmb_hash_table {
    size_t count;
    size_t size;
    gmb_hash_item** items;
}gmb_hash_table;

#endif