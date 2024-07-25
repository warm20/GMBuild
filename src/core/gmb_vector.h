#ifndef _GMB_VECTOR_H_
#define _GMB_VECTOR_H_
#include <stdlib.h>

typedef struct gmb_vector{
	void* buf_p;
	size_t buf_sz;
	size_t ele_sz;
	size_t size;
	int cour;
}gmb_vector;

/*
   Create the vector
*/
extern gmb_vector* gmb_vector_new(size_t ele_size);

/*
    Create the vector without the ptr
*/
extern gmb_vector gmb_vector_new_np(size_t ele_size);

/*
   Delete the vector
*/
extern void gmb_vector_del(gmb_vector *self);

/*
    Push the value to the vector
*/
extern void gmb_vector_push(gmb_vector* self, void* v);

/*
    Get the vec[i]
*/
extern void gmb_vector_get(gmb_vector *self, size_t i, void *res);

/*
    Pop the last
*/
extern void gmb_vector_popback(gmb_vector *self);

/*
    Iter for the vector
    use: same as the array
*/
extern void* gmb_vector_next(gmb_vector *self, void* it);

/*
    Ref iter for the vector
use: p=gmb_vector_ref_next(&vec);
*/
extern void* gmb_vector_ref_next(gmb_vector *self);

#endif
