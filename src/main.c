#include <stdio.h>
#include <string.h>

#define _GMB_SHORT_TYPE_

#include "./core/gmb_string.h"
#include "./core/gmb_array.h"
#include "./core/gmb_vector.h"
#include "./core/gmb_def.h"

int main(int argc, char *argv[], char *fenv[]) {
    vector v = gmb_vector_new_np(type(int));
    gmb_vector_del_np(&v);
}