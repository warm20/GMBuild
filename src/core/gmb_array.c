#include "./gmb_array.h"

#include <stdlib.h>
#include <string.h>

gmb_array* gmb_array_new(size_t ele_nums, size_t ele_size) {
    gmb_array *p = (gmb_array*)malloc(sizeof(gmb_array));
    p->ele_nums = ele_nums;
    p->ele_sz = ele_size;

    p->buffer = malloc( ele_nums * ele_size );
    return p;
}

gmb_array gmb_array_new_np(size_t ele_nums, size_t ele_size) {
    gmb_array p;
    p.ele_nums = ele_nums;
    p.ele_sz = ele_size;

    p.buffer = malloc( ele_nums * ele_size );
    return p;
}

int gmb_array_set(gmb_array *obj, size_t i, void* value) {
    if(i<0 || i>obj->ele_nums) {
        return -1;
    }
    memcpy(obj->buffer + i*obj->ele_sz, value, obj->ele_sz);
    return 0;
}

void gmb_array_get(gmb_array *obj, size_t i, void* result) {
    if(i > obj->ele_nums || i<0) {
        result=NULL;
        return;
    }
    memcpy(result, obj->buffer + (i * obj->ele_sz), obj->ele_sz);
}