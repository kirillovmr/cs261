
/*
 * Viktor Kirillov vkiril2
*  Volodymyr Vakhniuk vvakhn2
 *
You are allowed to use looping and conditional control.
You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.
     This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


 * float_four_times - Return bit-level equivalent of expression 4.0*f for
 *   floating point argument uf.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 */
unsigned float_four_times(unsigned uf) {
  
    int exp = uf & 0x7F800000;
    int fr = uf & 0x007FFFFF;
    
    // If NaN
    if (exp == 0x7F800000)
        return uf;
    
    // Normalized
    if (exp != 0x0) {
        exp <<= 2;
        return (uf & 0x807FFFFF) | exp ;
    }
    // Denormalized
    else {
        // Remains denormalized
        if (fr <= 0x00200000) {
            fr <<= 2;
            return (uf & 0xFF800000) | fr ;
        }
        // Becomes Normalized
        else {
            fr = (uf & 0x00FFFFFF) << 2;
            fr += ((uf & 2) << 2) & (uf & 1);
            return (0x80000000 & uf) | fr;
        }
    }
}
