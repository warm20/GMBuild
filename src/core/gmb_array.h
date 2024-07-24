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
extern void gmb_array_del(gmb_array *obj);

/*
    run the p.arr[i]=value
*/
extern int gmb_array_set(gmb_array *obj, size_t i, void* value);

/*
    run the result = p.arr[i]
    example to use:
        void *p = malloc(sizeof(type));
        gmb_array_get(arr,n,p)
        type res = *(type*)p
*/
extern void gmb_array_get(gmb_array *obj, size_t i, void* result);

/*
	This func will get the value first
	And then return next
	
	use:
		while(gmb_array_iter_next(arr, p)) {
			...
		}
*/
extern void* gmb_array_next(gmb_array *obj, void *it);

#endif
