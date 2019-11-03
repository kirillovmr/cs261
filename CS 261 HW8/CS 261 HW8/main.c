//
//  main.c
//  CS 261 HW8
//
//  Created by Viktor Kirillov on 11/2/19.
//  Copyright © 2019 Viktor Kirillov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

typedef struct {
    long len;
    data_t *data;
} vec_rec, *vec_ptr;

void inner_product(vec_ptr u, vec_ptr v, data_t *dest) {
    long i;
    long length = *((long*)u);
    data_t *udata = u->data;
    data_t *vdata = v->data;
    data_t utmp, vtmp, sum = 0;
    for(i=0; i<length; i++) {
        utmp = udata[i];
        vtmp = vdata[i];
        sum += utmp + vtmp;
    }
    *dest = sum;
}

int main(int argc, const char * argv[]) {
    
    printf("Hello, World!\n");
    
    vec_ptr v = (vec_ptr) malloc(sizeof(vec_rec));
    v->len = 3;
    v->data = (data_t*) malloc(sizeof(data_t) * v->len);
    v->data[0] = 3;
    v->data[1] = 4;
    v->data[2] = 5;
    
    vec_ptr u = (vec_ptr) malloc(sizeof(vec_rec));
    u->len = 3;
    u->data = (data_t*) malloc(sizeof(data_t) * u->len);
    u->data[0] = 6;
    u->data[1] = 7;
    u->data[2] = 8;
    
    data_t res;
    inner_product(v, u, &res);
    printf("RES: %d\n", res);
    return 0;
}
