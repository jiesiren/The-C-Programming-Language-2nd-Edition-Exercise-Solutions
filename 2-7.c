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

unsigned int invert(unsigned int x, unsigned int p, unsigned int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}

int main(void) {
    int x = 9713;
    int p = 11;
    int n = 5;

    print_binary(x);
    printf(" = x");
    putchar('\n');

    // highlight n bits from position p
    print_range_indic(p, n, '^');
    putchar('\n');

    for (unsigned int i = 0; i < UI_NUM_BITS; i++) {
        putchar('-');
    }
    putchar('\n');

    print_binary(invert(x, p, n));
    printf(" = invert(x, %d, %d)", p, n);
    putchar('\n');

    // highlight n bits from position p
    print_range_indic(p, n, '^');
    putchar('\n');

    return 0;
}
