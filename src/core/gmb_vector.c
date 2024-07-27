#include "./gmb_vector.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

// -----------Create&Delete-------------
/*
    Create the vector object
*/
gmb_vector* gmb_vector_new(size_t ele_size)
{
    gmb_vector* p = (gmb_vector*)malloc(sizeof(gmb_vector));
    p->buf_sz = 10;
    p->ele_sz = ele_size;
    p->buf_p = malloc(ele_size*10);
    p->size = 0;
    p->cour = 0;
    return p;
}

/*
    Create the vector object without the ptr
*/
gmb_vector gmb_vector_new_np(size_t ele_size)
{
    gmb_vector p;
    p.buf_sz = 10;
    p.ele_sz = ele_size;
    p.buf_p = malloc(ele_size*10);
    p.size = 0;
    p.cour = 0;
    return p;
}

/*
    Delete the vector that create with ptr
*/
void gmb_vector_del(gmb_vector *self)
{
    if(self == NULL) return;
    free(self->buf_p);
    self->buf_p = NULL;
    free(self);
    self = NULL;
}

/*
    Delete the vector that create without the ptr
*/
void gmb_vector_del_np(gmb_vector *self)
{
    gmb_vector_del(self);
}


// -----------Operators-------------
/*
    Push a new element to the vector
*/
void gmb_vector_push(gmb_vector *self, void *v)
{
    self->size += 1;
    if(self->buf_sz < self->size) { // recall the memory
        self->buf_p = realloc(self->buf_p,self->ele_sz*(self->size+10));
        self->buf_sz += 10;
    }
    memcpy(self->buf_p+(self->size-1)*self->ele_sz, v, self->ele_sz);
}

/*
    Pop the last element
*/
void gmb_vector_popback(gmb_vector *self)
{
    if(self->size > 0) self->size -= 1;
}

/*
    Get a element by the index
*/
void gmb_vector_get(gmb_vector *self, size_t i, void *res)
{
    if(i<0 || i>self->size){
        res = NULL;
        return;
    }
    memcpy(res, self->buf_p+(i*self->ele_sz), self->ele_sz);
}

/*
    Iter(only read)
*/
void* gmb_vector_next(gmb_vector *self, void* it)
{
    if(self->cour >= self->size) {
        self->cour = 0;
        it = NULL;
        return NULL;
    }
    memcpy(it, self->buf_p+self->cour*self->ele_sz, self->ele_sz);
    self->cour += 1;
    return it;
}

/*
    Iter(read/wirte)
*/
void* gmb_vector_ref_next(gmb_vector *self)
{
    if(self->cour >= self->size) {
        self->cour = 0;
        return NULL;
    }
    self->cour += 1;
    return self->buf_p + self->cour*self->ele_sz;
}
