#include <stdio.h>

int main(void) {
    int c, num_ws;

    num_ws = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            num_ws++;
        }
    }

    printf("Number of whitespace characters: %d\n", num_ws);

    return 0;
}
