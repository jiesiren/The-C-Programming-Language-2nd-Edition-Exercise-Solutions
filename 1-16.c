#include <stdio.h>

#define MAXLINE 10

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("Longest len: %d\n", max);
        printf("%s", longest);
    }

    return 0;
}

int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF
            && c != '\n'; i++) {
        s[i] = c;
    }
    // if limit reached, save current buffer s as the full line and
    // read in the rest of the characters in the line without copying
    if (i == lim - 1) {
        s[i - 1] = '\n';
        s[i] = '\0';
        while ((c = getchar()) != EOF && c != '\n') {
            i++;
        }
    } else {
        if (c == '\n') {
            s[i] = c;
            i++;
        }
        s[i] = '\0';
    }
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
