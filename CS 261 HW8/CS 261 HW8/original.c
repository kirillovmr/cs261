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
    
/* Return length of vector */
long vec_length(vec_ptr v) {
    return v->len;
}
    
int get_vec_element(vec_ptr v, long index, data_t *dest){
    if (index < 0 || index >= v->len)
        return 0;
    *dest = v->data[index];
    return 1;
}
    
/*Return pointer to start of vector data*/
data_t *get_vec_start(vec_ptr v) {
    return v->data;
}

void inner_product(vec_ptr u, vec_ptr v, data_t *dest) {
    long i;
    long length = vec_length(u); // remove call
    data_t udata;
    data_t vdata;
    data_t sum = (data_t) 0; // no need to convert in our case
    for(i=0; i<vec_length(u); i++) { // use length
        vec_ptr a = u; // remove, unnecessary
        vec_ptr b = v; // declare unnecessary
        get_vec_element(a,i,&udata);
        get_vec_element(b,i,&vdata);
        *dest = *dest + udata + vdata; // writing to temp instead of memory
    }
}

//int main(int argc, const char * argv[]) {
//    
//    printf("Hello, World!\n");
//    
//    vec_ptr v = (vec_ptr) malloc(sizeof(vec_rec));
//    v->len = 3;
//    v->data = (data_t*) malloc(sizeof(data_t) * v->len);
//    v->data[0] = 3;
//    v->data[1] = 4;
//    v->data[2] = 5;
//    
//    vec_ptr u = (vec_ptr) malloc(sizeof(vec_rec));
//    u->len = 3;
//    u->data = (data_t*) malloc(sizeof(data_t) * u->len);
//    u->data[0] = 6;
//    u->data[1] = 7;
//    u->data[2] = 8;
//    
//    data_t res;
//    inner_product(v, u, &res);
//    printf("RES: %d\n", res); // 33
//    return 0;
//}
