#include "gmb_string.h"
#include "gmb_array.h"

#include <stdlib.h>

gmb_string* gmb_string_new(char init_s[]) {
    gmb_string *p = (gmb_string*)malloc(sizeof(gmb_string));
    size_t s_len = strlen(init_s);
    // data set
    p->str_p = (char*)malloc(sizeof(char)*(s_len+1));
    strcpy(p->str_p, init_s);
    p->str_len = s_len;
    // return ptr
    return p;
}

gmb_string gmb_string_new_np(char init_s[]) {
    gmb_string p;
    size_t s_len = strlen(init_s);
    p.str_p = (char*)malloc(sizeof(char)*(s_len+1));
    strcpy(p.str_p, init_s);
    p.str_len = s_len;
    return p;
}

int gmb_add_string(gmb_string *obj, const char* str) {
    // get string length
    size_t obj_s_l = strlen(obj->str_p);
    size_t str_l = strlen(str);
    // call the memory
    obj->str_p = realloc(obj->str_p, (obj_s_l+str_l+1)*sizeof(char));
    if(obj->str_p == NULL) return -1;

    // set ptr offset
    char *new_p = (obj->str_p + obj_s_l);
    if(strcpy(new_p, str)==NULL) return 1;
    obj->str_len = obj_s_l+str_l;
    return 0;
}

int gmb_merge_str(gmb_string *a,gmb_string *b) {
    const char* b_str = b->str_p;
    return gmb_add_string(a, b_str); // call add
}

void gmb_del_string(gmb_string *obj) {
    // check the object
    if(obj == NULL) return;
    // free memory
    if(obj->str_p != NULL) free(obj->str_p);
    if(obj != NULL) free(obj);
    // set ptr point
    obj->str_p = NULL;
    obj = NULL;
    return;
}
