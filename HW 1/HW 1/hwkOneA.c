//
//  main.c
//  HW 1
//
//  Created by Viktor Kirillov on 9/7/19.
//  Copyright © 2019 Viktor Kirillov. All rights reserved.
//

//#include <stdio.h>
//
//long int hwkOneA(long int x, int n, int m);
//long int hwkOneA1(long int x, int n, int m);
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("%lx\n", hwkOneA(0x0123456789abcdef,3,10));
//    return 0;
//}

long int hwkOneA(long int x, int n, int m) {
    int n1 = 4*(16-n-1), m1 = 4*(16-m-1);
    long int x2 = x, q = 0xF;
    
    // Clear n.th byte
    x = x ^ (x & (q<<n1));
    
    // Put m.th byte onto n.th byte
    x = x | ((x & (q<<m1)) >> m1) << n1;
    
    // Clear m.th byte
    x = x ^ (x & (q<<m1));
    
    // Put n.th byte onto m.th byte
    x = x | ((x2 & (q<<n1)) >> n1) << m1;
    
    return x;
}
