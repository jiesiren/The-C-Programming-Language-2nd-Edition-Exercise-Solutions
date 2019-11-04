#include <stdio.h>

// https://www.quora.com/What-is-the-purpose-of-using-do-while-0-in-macros
// tldr: do-while results in a single statement and not a compound statement
// which can mess up macro uses that replace single statements (eg. use in
// if statement without braces as single statement).
#define swap(t, x, y) do {t tmp = x; x = y; y = tmp;} while (0)

int main(void) {
    int a = 1;
    int b = 2;

    swap(int, a, b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
