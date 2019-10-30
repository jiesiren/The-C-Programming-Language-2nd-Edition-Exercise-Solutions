#include <stdio.h>

char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

int main(void) {
    char s[] = "hElLo WoRlD!!1";

    for (int i = 0; s[i]; i++) {
        putchar(lower(s[i]));
    }
    putchar('\n');

    return 0;
}
