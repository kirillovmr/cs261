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

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("\n%lx\n", hwkOneA(0xF000000000000010,0,15));
    return 0;
}

long int hwkOneA(long int x, int n, int m) {
    int n1 = 4*(16-n-1), m1 = 4*(16-m);
    long int x2 = x, q = 0xf;
    printf("%lx\n", x);
    
    // Clear n.th byte
    x = x ^ (x & (q<<n1));
    
    printf("%lx\n", x | ((x & (q<<m1)) >> m1) << n1   );
    // Put m.th byte onto n.th byte
    x = x | ((x & (q<<m1)) >> m1) << n1;
    
    printf("%lx\n", x);
    
    // Clear m.th byte
    x = x ^ (x & (q<<m1));
    
    printf("\n%lx\n", x2);
    printf("%lx\n",  x | (((x2 & (q<<n1)) >> n1) ^ (q<<n1)>>(n1-4)) << m1  );
//    printf("%lx\n",     );
    
    // Put n.th byte onto m.th byte
    x = x | ((x2 & (q<<n1)) >> n1) << m1;
    
    return x;
}
