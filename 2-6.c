#include <stdio.h>
#include <limits.h>

#define UI_NUM_BITS (sizeof(unsigned int) * CHAR_BIT)

void print_binary(unsigned int n) {
    for (int i = UI_NUM_BITS - 1; i >= 0; i--) { // i = index offset from the rightmost bit
        putchar(((1 << i) & n) ? '1' : '0');
    }
}

unsigned int setbits(unsigned int x, unsigned int p, unsigned int n,
                     unsigned int y) {
    const unsigned int rm_n_mask = ~(~0U << n);
    const unsigned int y_rm_n = y & rm_n_mask;
    const unsigned int align_shift = (p - n + 1);
    return (x & ~(rm_n_mask << align_shift)) // clear bit range in x
            | (y_rm_n << align_shift); // set to bit range from y
}

int main(void) {
    int x = 9713;
    int y = 3500;
    int p = 11;
    int n = 5;

    printf("x = ");
    print_binary(x);
    putchar('\n');

    // highlight n bits from position p
    for (unsigned int i = 0; i < UI_NUM_BITS + 4; i++) {
        if (i >= UI_NUM_BITS + 4 - p - 1 && i < UI_NUM_BITS + 4 - p - 1 + n) {
            putchar('^');
        } else {
            putchar(' ');
        }
    }
    putchar('\n');

    printf("y = ");
    print_binary(y);
    putchar('\n');

    // highlight last n bits of y
    for (unsigned int i = 0; i < UI_NUM_BITS + 4; i++) {
        if (i >= UI_NUM_BITS + 4 - n) {
            putchar('^');
        } else {
            putchar(' ');
        }
    }
    putchar('\n');

    for (unsigned int i = 0; i < UI_NUM_BITS + 4; i++) {
        putchar('-');
    }
    putchar('\n');

    printf("res=");
    print_binary(setbits(x, p, n, y));
    putchar('\n');

    // highlight n bits from position p
    for (unsigned int i = 0; i < UI_NUM_BITS + 4; i++) {
        if (i >= UI_NUM_BITS + 4 - p - 1 && i < UI_NUM_BITS + 4 - p - 1 + n) {
            putchar('^');
        } else {
            putchar(' ');
        }
    }
    putchar('\n');

    return 0;
}
