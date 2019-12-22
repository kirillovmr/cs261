
#include <stdio.h>
#include "bits.c"

int main() {
    unsigned int X = 0x002F0001;

    
    printf("%u returned %u\n",X,float_four_times(0x002F0001));
    printf("%u returned %u\n",X,float_four_times(0x00000001));
    printf("%u returned %u\n",X,float_four_times(0xFF800001));
    printf("%u returned %u\n",X,float_four_times(X));

    /*
    Include 4 more test cases (other than testing 0 above) that test your float_four_times() function with expected results.
    Be sure to list the 32-bit float pattern you used as input and the 32-bit float pattern you expected as output.
    */

    return 0;


}
