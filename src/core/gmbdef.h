#ifndef _GMB_DEF_H_
#define _GMB_DEF_H_
#include<stdlib.h>

#define gn_conv(T,A) *(T*)A
#define new_gn_ptr(T) malloc(sizeof(T))
#define type(x) sizeof(x)

#ifdef _GMB_SHORT_TYPE_

typedef gmb_array array;
typedef gmb_string string;

#endif

#endif
