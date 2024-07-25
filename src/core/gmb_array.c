#include "./gmb_array.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

gmb_array* gmb_array_new(size_t ele_nums, size_t ele_size) {
    gmb_array *p = (gmb_array*)malloc(sizeof(gmb_array));
    p->ele_nums = ele_nums;
    p->ele_sz = ele_size;
    p->cour = 0;

    p->buffer = calloc(ele_nums, ele_size);
    return p;
}

gmb_array gmb_array_new_np(size_t ele_nums, size_t ele_size) {
    gmb_array p;
    p.ele_nums = ele_nums;
    p.ele_sz = ele_size;
    p.cour = 0;

    p.buffer = calloc(ele_nums, ele_size);
    return p;
}

void gmb_array_del(gmb_array *self) {
    if(self==NULL) return;
    free(self->buffer);
    self->buffer = NULL;
    free(self);
    self = NULL;
    return;
}

int gmb_array_set(gmb_array *self, size_t i, void* value) {
    if(i<0 || i>self->ele_nums) {
        return -1;
    }
    memcpy(self->buffer + i*self->ele_sz, value, self->ele_sz);
    return 0;
}

void gmb_array_get(gmb_array *self, size_t i, void* result) {
    if(i > self->ele_nums || i<0) {
        result=NULL;
        return;
    }
    memcpy(result, self->buffer + (i * self->ele_sz), self->ele_sz);
}

void* gmb_array_next(gmb_array *self, void *it) {
    if(self->cour >= self->ele_nums) {
        self->cour = 0; // reset the iter courser
		it = NULL;
        return NULL; // the end
    }
    memcpy(it, self->buffer+self->cour*self->ele_sz, self->ele_sz);
    self->cour += 1;
    return it;
}

void* gmb_array_ref_next(gmb_array *self){
	if(self->cour >= self->ele_nums) {
		self->cour = 0; // reset the iter courser
		return NULL; // the end
	}
	self->cour += 1;
	return self->buffer + (self->cour * self->ele_sz);
}
