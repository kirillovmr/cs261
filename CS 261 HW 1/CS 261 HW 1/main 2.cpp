//
//  main.cpp
//  CS 261 HW 1
//
//  Created by Viktor Kirillov on 9/4/19.
//  Copyright © 2019 Viktor Kirillov. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

long int hwkOneA(long int, int, int);

int main(int argc, const char * argv[]) {
    
//    int a = 3, b = 5;
//    a = a ^ b;
//    b = a ^ b;
//    a = a ^ b;
//    cout << a << "  " << b << endl;
    
    std::cout << std::hex << hwkOneA(0x0123456789ABCDEF, 2, 11) << std::endl;
    
    return 0;
}

long int hwkOneA(long int x, int n, int m) {
    typedef unsigned char *byte_pointer;
    byte_pointer start = (byte_pointer) &x;
    
    int bytePos1 = sizeof(x)-1-n/2, bytePos2 = sizeof(x)-1-m/2;
    unsigned char newByte1, newByte2, tempByte1, tempByte2;
    int index1 = n%2, index2 = m%2;
    
    for (int i=sizeof(x)-1; i>=0; i--)
        printf("%.2x ", start[i]);
    cout << endl;
    
    // Changing first byte
    if (index1 == 0) {
        newByte1 = start[bytePos1] & 0x0F;
        if (index2 == 0)
            tempByte1 = start[bytePos2] & 0xF0;
        else
            tempByte1 = (start[bytePos2] & 0x0F) << 4;
    }
    else {
        newByte1 = start[bytePos1] & 0xF0;
        if (index2 == 0)
            tempByte1 = start[bytePos2]>>4;
        else
            tempByte1 = start[bytePos2] & 0x0F;
    }
    
    // Changing second byte
    if (index2 == 0) {
        newByte2 = start[bytePos2] & 0x0F;
        if (index1 == 0)
            tempByte2 = start[bytePos1] & 0xF0;
        else
            tempByte2 = (start[bytePos1] & 0x0F) << 4;
    }
    else {
        newByte1 = start[bytePos2] & 0xF0;
        if (index1 == 0)
            tempByte2 = start[bytePos1]>>4;
        else
            tempByte2 = start[bytePos1] & 0x0F;
    }
    
    start[bytePos1] = newByte1 | tempByte1;
    start[bytePos2] = newByte2 | tempByte2;
    
    printf("%.2x \n", start[bytePos1]<<4>>4);
    printf("%.2x \n\n", start[bytePos2] & 0xF0);
    
    for (int i=sizeof(x)-1; i>=0; i--)
        printf("%.2x ", start[i]);
    cout << endl;
    
    std::cout << std::hex;
    return x;
}
