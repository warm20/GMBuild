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

int gmb_string_add(gmb_string *self,const char *str) {
    // get string length
    size_t self_s_l = strlen(self->str_p);
    size_t str_l = strlen(str);
    // call the memory
    self->str_p = realloc(self->str_p, (self_s_l+str_l+1)*sizeof(char));
    if(self->str_p == NULL) return -1;

    // set ptr offset
    char *new_p = (self->str_p + self_s_l);
    if(strcpy(new_p, str)==NULL) return 1;
    self->str_len = self_s_l+str_l;
    return 0;
}

int gmb_string_merge(gmb_string *a,gmb_string *b) {
    const char* b_str = b->str_p;
    return gmb_string_add(a, b_str); // call add
}

void gmb_string_del(gmb_string *self) {
    // check the selfect
    if(self == NULL) return;
    // free memory
    if(self->str_p != NULL) free(self->str_p);
    if(self != NULL) free(self);
    // set ptr point
    self->str_p = NULL;
    self = NULL;
    return;
}

void gmb_string_del_np(gmb_string *self) {
    free(self->str_p);
    self->str_p = NULL;
    return;
}

void gmb_string_reset(gmb_string *self,char str[]){
    free(self->str_p);
    size_t str_l = strlen(str);
    self->str_p = (char*)malloc(sizeof(char)*str_l);
    strcpy(self->str_p, str);
}
