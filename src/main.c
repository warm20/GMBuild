#include <stdio.h>
#include <string.h>

#include "./core/gmb_string.h"
#include "./core/gmb_array.h"
#include "./core/gmbdef.h"

int main(int argc, char *argv[], char *fenv[]) {
    gmb_array a = gmb_array_new_np(10,sizeof(int));
    for(int i=0;i<10;i++) {
        gmb_array_set(&a, i, &i);
    }
    for(int i=0;i<10;i++) {
        void* p = malloc(sizeof(int));
        gmb_array_get(&a,i,p);
        printf("%d ",GnConv(int, p));
    }
}