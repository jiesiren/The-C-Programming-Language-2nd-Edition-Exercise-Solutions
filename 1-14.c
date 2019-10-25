#include <stdio.h>

#define PLOT_CHAR '#'
#define ASCII_LIMIT 128

int main(void) {
    int c;

    // counts[i] will contain the number of characters of ASCII value i
    int counts[ASCII_LIMIT];

    for (int i = 0; i < ASCII_LIMIT; i++) {
        counts[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < ASCII_LIMIT) {
            counts[c]++;
        }
    }

    // Print horizontally
    for (int i = 0; i < ASCII_LIMIT; i++) {
        if (counts[i] != 0 && i >= ' ' && i <= '~') { // only print visible chars
            printf("%c ", i);
            for (int j = 0; j < counts[i]; j++) {
                putchar(PLOT_CHAR);
            }
            putchar('\n');
        }
    }

    return 0;
}
