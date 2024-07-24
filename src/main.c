#include <stdio.h>
#include <string.h>

#define _GMB_SHORT_TYPE_

#include "./core/gmb_string.h"
#include "./core/gmb_array.h"
#include "./core/gmb_vector.h"
#include "./core/gmb_def.h"

int main(int argc, char *argv[], char *fenv[]) {
    vector v = gmb_vector_new_np(type(array));
    for(int i=1;i<=5;i++) {
        array arr = gmb_array_new_np(5,type(int));
        for(int j=0;j<5;j++) {
            gmb_array_set(&arr, j, &j);
        }
        gmb_vector_push(&v, &arr);
    }
    void *it_v = new_gn_ptr(array);
    while(gmb_vector_iter_next(&v, it_v)) {
        void *t = new_gn_ptr(int);
        while(gmb_array_iter_next(&gn_conv(array, it_v), t)) {
            printf("%d ", gn_conv(int, t));
        }
        printf("\n");
    }
}