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

unsigned int rightrot(unsigned int x, unsigned int n) {
    const unsigned int rm_n = x & ~(~0U << n);
    const unsigned int left = x >> n;
    return (rm_n << (UI_NUM_BITS - n)) | left;
}

int main(void) {
    int x = 9713131;
    int n = 5;

    print_binary(x);
    printf(" = x");
    putchar('\n');

    // highlight the rightmost n bits
    print_range_indic(n - 1, n, '^');
    putchar('\n');

    for (unsigned int i = 0; i < UI_NUM_BITS; i++) {
        putchar('-');
    }
    putchar('\n');

    print_binary(rightrot(x, n));
    printf(" = rightrot(x, %d)", n);
    putchar('\n');

    // highlight leftmost n bits
    print_range_indic(UI_NUM_BITS - 1, n, '^');
    putchar('\n');
    return 0;
}
