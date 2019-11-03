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
    long lim = length - length % 6;
    data_t *udata = u->data;
    data_t *vdata = v->data;
    data_t utmp1, utmp2, vtmp1, vtmp2, sum = 0;
    for(i=0; i<lim; i+=6) {
        utmp1 = udata[i];
        vtmp1 = vdata[i];
        sum += utmp1 + vtmp1;
        utmp2 = udata[i+1];
        vtmp2 = vdata[i+1];
        sum += utmp2 + vtmp2;
        
        utmp1 = udata[i+2];
        vtmp1 = vdata[i+2];
        sum += utmp1 + vtmp1;
        utmp2 = udata[i+3];
        vtmp2 = vdata[i+3];
        sum += utmp2 + vtmp2;
        
        utmp1 = udata[i+4];
        vtmp1 = vdata[i+4];
        sum += utmp1 + vtmp1;
        utmp2 = udata[i+5];
        vtmp2 = vdata[i+5];
        sum += utmp2 + vtmp2;
    }
    
    for (; i<length; i++) {
        utmp1 = udata[i];
        vtmp1 = vdata[i];
        sum += utmp1 + vtmp1;
    }
    *dest = sum;
}

int main(int argc, const char * argv[]) {
    
    printf("Hello, World!\n");
    
    vec_ptr v = (vec_ptr) malloc(sizeof(vec_rec));
    v->len = 14;
    v->data = (data_t*) malloc(sizeof(data_t) * v->len);
    v->data[0] = 3;
    v->data[1] = 4;
    v->data[2] = 5;
    v->data[3] = 3;
    v->data[4] = 4;
    v->data[5] = 5;
    v->data[6] = 3;
    v->data[7] = 4;
    v->data[8] = 5;
    v->data[9] = 3;
    v->data[10] = 4;
    v->data[11] = 5;
    v->data[12] = 4;
    v->data[13] = 5;
    
    vec_ptr u = (vec_ptr) malloc(sizeof(vec_rec));
    u->len = 14;
    u->data = (data_t*) malloc(sizeof(data_t) * u->len);
    u->data[0] = 6;
    u->data[1] = 7;
    u->data[2] = 8;
    u->data[3] = 6;
    u->data[4] = 7;
    u->data[5] = 8;
    u->data[6] = 6;
    u->data[7] = 7;
    u->data[8] = 8;
    u->data[9] = 6;
    u->data[10] = 7;
    u->data[11] = 8;
    u->data[12] = 6;
    u->data[13] = 7;
    
    data_t res;
    inner_product(v, u, &res);
    printf("RES: %d\n", res); // 154
    return 0;
}
