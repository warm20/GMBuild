#ifndef _GMB_ARRAY_H_
#define _GMB_ARRAY_H_
#include <stdlib.h>
#include <stddef.h>

typedef struct gmb_array
{
    size_t ele_sz;
    size_t ele_nums;
    void *buffer;
    int cour;
}gmb_array;

/*
    Create the array
*/
extern gmb_array* gmb_array_new(size_t ele_nums, size_t ele_size);

/*
    Create the array with out ptr
*/
extern gmb_array gmb_array_new_np(size_t ele_nums, size_t ele_size);

/*
    Delete the array
*/
extern void gmb_array_del(gmb_array *self);

/*
    Delete the array
*/
extern void gmb_array_del_np(gmb_array *self);

/*
    run the p.arr[i]=value
*/
extern int gmb_array_set(gmb_array *self, size_t i, void* value);

/*
    run the result = p.arr[i]
    example to use:
        void *p = malloc(sizeof(type));
        gmb_array_get(arr,n,p)
        type res = *(type*)p
*/
extern void gmb_array_get(gmb_array *self, size_t i, void* result);

/*
	This func will get the value first
	And then return next
	(only read)
	use:
		while(gmb_array_iter_next(arr, p)) {
			...
		}
*/
extern void* gmb_array_next(gmb_array *self, void *it);

/*
    ref iter for the array(read/write)
use:
    p = gmb_array_ref_next(&arr);
*/
extern void* gmb_array_ref_next(gmb_array *self);

#endif
