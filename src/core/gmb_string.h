#ifndef _GMB_STRING_H_
#define _GMB_STRING_H_
#include <stdlib.h>
#include <string.h>

#include "./gmb_array.h"

typedef struct gmb_string {
    char *str_p;
    size_t str_len;
}gmb_string;

/*
    Init the gmb_string selfect
*/
extern gmb_string* gmb_string_new(char init_s[]);

/*
    Create the gmb_string selfect without the ptr
*/
extern gmb_string gmb_string_new_np(char init_s[]);

/*
    Delete the gmb_string selfect
*/
extern void gmb_string_del(gmb_string *self);

/*
    Delete the gmb_string selfect with out the ptr
*/
extern void gmb_string_del_np(gmb_string *self);


/* 
    add_string run self+=str
*/
extern void gmb_string_add(gmb_string *self,const char *str);

/*
    merge_str run a+b->a
*/
extern void gmb_string_merge(gmb_string *a, gmb_string *b);

/*
    reset the content of the string
*/
extern void gmb_string_reset(gmb_string *self, char str[]);


#endif // _GMB_STRING_H_
