//
//  main.cpp
//  CS 261 HW 1
//
//  Created by Viktor Kirillov on 9/4/19.
//  Copyright © 2019 Viktor Kirillov. All rights reserved.
//

#include <iostream>

using namespace std;

long int hwkOneA(long int, int, int);

int main(int argc, const char * argv[]) {
    
//    int a = 3, b = 5;
//    a = a ^ b;
//    b = a ^ b;
//    a = a ^ b;
//    cout << a << "  " << b << endl;
    
    std::cout << hwkOneA(0x0123456789ABCDEF, 3, 10) << std::endl;
    
    return 0;
}

long int hwkOneA(long int x, int n, int m) {
    typedef unsigned char *byte_pointer;
    byte_pointer start = (byte_pointer) &x;
    unsigned char newByte1, newByte2, tempByte1, tempByte2;
    int indexByte1 = sizeof(x)-1-n/2, indexByte2 = sizeof(x)-1-m/2;
    int index1 = n % 2, index2 = m % 2;
    
    for (int i=sizeof(x)-1; i>=0; i--)
        printf("%.2x ", start[i]);
    cout << endl;
    
    // Changing first byte
    if (index1 == 0) {
        newByte1 = start[indexByte1] & 0x0f;
        if (index2 == 0)
            tempByte1 = start[indexByte2] & 0xf0;
        else
            tempByte1 = (start[indexByte2] & 0x0f) << 4;
    }
    else {
        newByte1 = start[indexByte1] & 0xf0;
        if (index2 == 0)
            tempByte1 = (start[indexByte2] & 0xf0) >> 4;
        else
            tempByte1 = start[indexByte2] & 0x0f;
    }
    
    // Changing second byte
    if (index2 == 0) {
        newByte2 = start[indexByte2] & 0x0f;
        if (index1 == 0)
            tempByte2 = start[indexByte1] & 0xf0;
        else
            tempByte2 = (start[indexByte1] & 0x0f) << 4;
    }
    else {
        newByte2 = start[indexByte2] & 0xf0;
        if (index1 == 0)
            tempByte2 = (start[indexByte1] & 0xf0) >> 4;
        else
            tempByte2 = start[indexByte1] & 0x0f;
    }
    start[indexByte1] = newByte1 | tempByte1;
    start[indexByte2] = newByte2 | tempByte2;
    
    for (int i=sizeof(x)-1; i>=0; i--)
        printf("%.2x ", start[i]);
    cout << endl;
    
    cout << std::hex;
    return x;
}
