#include <stdio.h>
#include <limits.h>

#define UI_NUM_BITS (sizeof(unsigned int) * CHAR_BIT)

void print_binary(unsigned int n) {
    for (int i = UI_NUM_BITS - 1; i >= 0; i--) { // i = index offset from the rightmost bit
        putchar(((1 << i) & n) ? '1' : '0');
    }
}

void print_range_indic(unsigned int p, unsigned int n, char indic_c) {
    for (unsigned int i = 0; i < UI_NUM_BITS; i++) {
        if (i >= UI_NUM_BITS - p - 1 && i < UI_NUM_BITS - p - 1 + n) {
            putchar(indic_c);
        } else {
            putchar(' ');
        }
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

    print_binary(x);
    printf(" = x");
    putchar('\n');

    // highlight n bits from position p
    print_range_indic(p, n, '^');
    putchar('\n');

    print_binary(y);
    printf(" = y");
    putchar('\n');

    // highlight last n bits of y
    print_range_indic(n - 1, n, '^');
    putchar('\n');

    for (unsigned int i = 0; i < UI_NUM_BITS; i++) {
        putchar('-');
    }
    putchar('\n');

    print_binary(setbits(x, p, n, y));
    printf(" = setbits(x, %d, %d, y)", p, n);
    putchar('\n');

    // highlight n bits from position p
    print_range_indic(p, n, '^');
    putchar('\n');

    return 0;
}
