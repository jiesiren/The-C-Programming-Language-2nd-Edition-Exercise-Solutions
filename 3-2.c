#include <stdio.h>

#define BUF_SIZE 1000

// assumes t is big enough to hold transformed s
void escape(char s[], char t[]) {
    int s_i = 0;
    int t_i = 0;

    while (1) {
        switch (s[s_i]) {
            case '\a':
                t[t_i++] = '\\';
                t[t_i++] = 'a';
                break;
            case '\b':
                t[t_i++] = '\\';
                t[t_i++] = 'b';
                break;
            case '\f':
                t[t_i++] = '\\';
                t[t_i++] = 'f';
                break;
            case '\n':
                t[t_i++] = '\\';
                t[t_i++] = 'n';
                break;
            case '\r':
                t[t_i++] = '\\';
                t[t_i++] = 'r';
                break;
            case '\t':
                t[t_i++] = '\\';
                t[t_i++] = 't';
                break;
            case '\v':
                t[t_i++] = '\\';
                t[t_i++] = 'v';
                break;
            default:
                t[t_i++] = s[s_i];
                break;
        }

        // break once '\0' is copied
        if (!s[s_i]) {
            break;
        }

        s_i++;
    }
}

int main(void) {
    char s[] = "Hello \t \n world!";
    char t[BUF_SIZE];

    printf("Before:\n%s\n", s);

    escape(s, t);

    printf("After:\n%s\n", t);

    return 0;
}
