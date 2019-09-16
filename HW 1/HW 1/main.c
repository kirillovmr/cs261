//
//  main.c
//  HW 1
//
//  Created by Viktor Kirillov on 9/7/19.
//  Copyright © 2019 Viktor Kirillov. All rights reserved.
//

#include <stdio.h>

long int hwkOneA(long int x, int n, int m);
long int hwkOneA1(long int x, int n, int m);
void runTests(void);

int main(int argc, const char * argv[]) {
//    runTests();
    float a = 17.1;
    int16_t b = a;
    printf("%d \n", a);
    if (b > 0)
        while (b) {
            if (b & 1)
                printf("1");
            else
                printf("0");
            
            b >>= 1;
        }
    printf("\n");
    printf("%X \n", a);
    
    return 0;
}

long int hwkOneA(long int x, int n, int m) {
    int n1 = 4*(16-n-1), m1 = 4*(16-m-1);
    long int x2 = x, q = 0xf;
    
    // Clear n.th byte
    x = x ^ (x & (q<<n1));
    
    // Put m.th byte onto n.th byte
    x = x | ((x & (q<<m1)) >> m1) << n1;
    
    // Clear m.th byte
    x = x ^ (x & (q<<m1));
    
    // Put n.th byte onto m.th byte
    x = x | (((x2 & (q<<n1)) >> n1) & 0xf) << m1;
    
    return x;
}

void runTests() {
    long int tes[] = {
        0x0123456789ABCDEF, 3, 10, 0x012A4567893BCDEF,
        0x00DCBA9876543210, 1, 2,  0x0D0CBA9876543210,
        0xF000000000000010, 0, 15, 0x000000000000001F
    };

    for (int i=0; i<sizeof(tes)/sizeof(tes[0])/4; i++) {
        long int res = hwkOneA(tes[i*4], (int)tes[i*4+1], (int)tes[i*4+2]);
        printf("TEST %d %s: %lx %d %d \n", i+1, tes[i*4+3]==res?"OK":"WRONG", tes[i*4], (int)tes[i*4+1], (int)tes[i*4+2]);
        printf("EXP: %lx\n", tes[i*4+3]);
        printf("RES: %lx\n\n", res);
    }
}
