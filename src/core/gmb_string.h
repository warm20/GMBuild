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
    Init the gmb_string object
*/
extern gmb_string* gmb_string_new(char init_s[]);

/*
    Create the gmb_string object without the ptr
*/
extern gmb_string gmb_string_new_np(char init_s[]);

/*
    Delete the gmb_string object
*/
extern void gmb_del_string(gmb_string *obj);

/* 
    add_string run obj+=str
*/
extern int gmb_add_string(gmb_string *obj,const char *str);

/*
    merge_str run a+b->a
*/
extern int gmb_merge_str(gmb_string *a,gmb_string *b);


#endif // _GMB_STRING_H_