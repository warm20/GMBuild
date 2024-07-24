#include "./gmb_vector.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

gmb_vector* gmb_vector_new(size_t ele_size) {
    gmb_vector* p = (gmb_vector*)malloc(sizeof(gmb_vector));
    p->buf_sz = 10;
    p->ele_sz = ele_size;
    p->buf_p = malloc(ele_size*10);
    p->size = 0;
    p->cour = 0;
    return p;
}

gmb_vector gmb_vector_new_np(size_t ele_size) {
    gmb_vector p;
    p.buf_sz = 10;
    p.ele_sz = ele_size;
    p.buf_p = malloc(ele_size*10);
    p.size = 0;
    p.cour = 0;
    return p;
}

void gmb_vector_del(gmb_vector *self) {
    if(self == NULL) return;
    free(self->buf_p);
    self->buf_p = NULL;
    free(self);
    self = NULL;
}

void gmb_vector_push(gmb_vector *self, void *v) {
    self->size += 1;
    if(self->buf_sz < self->size) { // 重新申请内存
        self->buf_p = realloc(self->buf_p,self->ele_sz*(self->size+10));
        self->buf_sz += 10;
    }
    memcpy(self->buf_p+(self->size-1)*self->ele_sz, v, self->ele_sz);
}

void gmb_vector_popback(gmb_vector *self) {
    if(self->size > 0) self->size -= 1;
}

void gmb_vector_get(gmb_vector *self, size_t i, void *res) {
    if(i<0 || i>self->size){
        res = NULL;
        return;
    }
    memcpy(res, self->buf_p+(i*self->ele_sz), self->ele_sz);
}

void* gmb_vector_next(gmb_vector *self, void* it) {
    if(self->cour >= self->size) {
        self->cour = 0;
        return NULL;
    }
    memcpy(it, self->buf_p+self->cour*self->ele_sz, self->ele_sz);
    self->cour += 1;
    return it;
}
