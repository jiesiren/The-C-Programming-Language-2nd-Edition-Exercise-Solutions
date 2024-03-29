#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        while (len > 0 && (line[len-1] == ' ' || line[len-1] == '\t'
                || line[len-1] == '\n')) {
            line[len-1] = '\0';
            len--;
        }
        if (len > 0) {
            printf("%s\n", line);
        }
    }
    return 0;
}

int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF
            && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
