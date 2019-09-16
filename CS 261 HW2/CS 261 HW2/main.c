//
//  main.c
//  CS 261 HW2
//
//  Created by Viktor Kirillov on 9/15/19.
//  Copyright © 2019 Viktor Kirillov. All rights reserved.
//

//#include <stdio.h>
//
//unsigned long hwkTwoC(unsigned long x, int n);
//void bin(unsigned long n);
//
//int main(int argc, const char * argv[]) {
//    printf("\nRes: %lX\n", hwkTwoC(0xA1CEA1CEA1CEA1CE, 3));
//    return 0;
//}

unsigned long hwkTwoC(unsigned long x, int n) {
    unsigned long leftNBitsMask = (0xFFFFFFFFFFFFFFFF >> (64-n)) << (64-n);
//    printf("leftNBitsMask: "); bin(leftNBitsMask); printf("\n");
    
    unsigned long leftNBits = x & leftNBitsMask;
//    printf("leftNBits: "); bin(leftNBits); printf("\n");
    
    unsigned long left32BitsMask = 0xFFFFFFFFFFFFFFFF << 32;
//    printf("left32BitsMask: "); bin(left32BitsMask); printf("\n");
    
    unsigned long left32Bits = x & left32BitsMask;
//    printf("left32Bits: "); bin(left32Bits); printf("\n");
    
    unsigned long left32BitsShiftedByN = left32Bits << n;
//    printf("left32BitsShiftedByN: "); bin(left32BitsShiftedByN); printf("\n");
    
    unsigned long left32Cleared = x & 0x00000000FFFFFFFF;
//    printf("left32Cleared: "); bin(left32Cleared); printf("\n");
    
    unsigned long newX = left32Cleared | left32BitsShiftedByN;
//    printf("newX: "); bin(newX); printf("\n");
    
    newX = newX | (leftNBits >> (32-n));
//    printf("oriX: "); bin(x); printf("\n");
//    printf("newX: "); bin(newX); printf("\n");
    
    return newX;
}

//void bin(unsigned long n) {
//    if (n > 1)
//        bin(n>>1);
//    printf("%lu", n & 1);
//}
