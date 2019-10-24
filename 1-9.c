#include <stdio.h>

int main() {
    int c, last_c;

    last_c = EOF;

    while ((c = getchar()) != EOF) {
        if (!(last_c == ' ' && c == ' ')) {
            putchar(c);
        }
        last_c = c;
    }
}
