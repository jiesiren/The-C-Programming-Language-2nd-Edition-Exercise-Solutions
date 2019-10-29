#include <stdio.h>

#define BUF_SIZE 1000

int get_line(char s[], int lim) {
    int c, i = 0;

    while (i < lim - 1) {
        if ((c = getchar()) == EOF) break;
        if (c == '\n') break;
        s[i] = c;
        i++;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}


int main(void) {
    char s[BUF_SIZE];

    while (get_line(s, BUF_SIZE) > 0) {
        printf("%s", s);
    }

    return 0;
}
