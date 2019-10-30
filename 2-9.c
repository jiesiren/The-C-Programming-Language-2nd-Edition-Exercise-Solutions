#include <stdio.h>
#include <limits.h>

#define UI_NUM_BITS (sizeof(unsigned int) * CHAR_BIT)

void print_binary(unsigned int n) {
    for (int i = UI_NUM_BITS - 1; i >= 0; i--) { // i = index offset from the rightmost bit
        putchar(((1 << i) & n) ? '1' : '0');
    }
}

int bitcount(unsigned int x) {
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}

/*
x &= (x-1) deletes the right most bit since subtracting one changes
the binary representation of x as follows: the rightmost 1 becomes a 0
and all bits (which are 0s) to the right become 1s

ex)

1101 => 1100
1110 => 1101
110101000 => 110100111

since all the bits to the right of and including that rightmost 1 is
effectively inverted, if we bitwise AND that result with the original
x, those bits will all be 0, ultimately only inverting the bit
that was originally the rightmost 1.
*/
int main(void) {
    int x = 1284719;

    print_binary(x);
    printf(" x\n");

    printf("bitcount(x) = %d\n", bitcount(x));

    return 0;
}
