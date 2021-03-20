#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns
    // 0 or 1)

    // 用被除数一直除以2直到结果为1/0.
    // or
    /*
    n=4 0000 0000 0000 0000 0000 0000 0001 0000
    x   nnnn nnnn nnnn nnnn nnnn nnnn nnn? nnnn 
    =>  0000 0000 0000 0000 0000 0000 000? 0000
    */
    unsigned tmp = 1;
    tmp = tmp << n;
    return !!(tmp&x);  
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    unsigned tmp = 1;
    tmp = tmp << n;
    int value = *x;
    if (v==0) {
        *x = (~tmp)&value;
    } else {
        *x = tmp|value;
    }
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
    /*
    n=4 tmp  0000 0000 0000 0000 0000 0000 0001 0000
    value    xxxx xxxx xxxx xxxx xxxx xxxx xxx? xxxx
    xor      zzzz zzzz zzzz zzzz zzzz zzzz zzzF zzzz
    &        0000 0000 0000 0000 0000 0000 000F 0000
    ~tmp     1111 1111 1111 1111 1111 1111 1110 1111
             xxxx xxxx xxxx xxxx xxxx xxxx xxx0 xxxx
    */
    unsigned tmp = 1;
    tmp = tmp << n;
    int value = *x;
    *x = ((tmp^value)&tmp)|(value&(~tmp));
}

