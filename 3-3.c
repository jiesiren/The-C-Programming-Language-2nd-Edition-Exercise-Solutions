#include <stdio.h>

#define BUF_SIZE 1000

// "a-a" => "a"
#define ALLOW_SAME 1
// "c-a" => "cba"
#define ALLOW_REVERSE 1

int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

int is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

int is_num(char c) {
    return c >= '0' && c <= '9';
}

int is_alphanum(char c) {
    return is_lower(c) || is_upper(c) || is_num(c);
}

// Returns 1 if "<c1>-<c2>" is a valid expandable range, 0 otherwise
int is_valid_range(char c1, char c2) {
    const int is_same_type = (is_lower(c1) && is_lower(c2))
        || (is_upper(c1) && is_upper(c2))
        || (is_num(c1) && is_num(c2));

    if (!is_same_type) return 0;

    if (!ALLOW_SAME && c1 == c2) return 0;

    if (!ALLOW_REVERSE && c1 > c2) return 0;

    return 1;
}

void expand(char s1[], char s2[]) {
    int i = 0, j = 0;
    char prev = '\0';

    while (s1[i]) {
        if (s1[i] == '-' && is_valid_range(prev, s1[i + 1])) {
            int dir = (prev < s1[i + 1]) ? 1 : -1;
            while (prev != s1[i + 1]) {
                prev += dir;
                s2[j] = prev;
                j++;
            }
            i += 2; // skip '-' and next char (range end char)
        } else {
            s2[j] = s1[i];
            prev = s1[i];
            j++;
            i++;
        }
    }
}

int main(void) {
    char s1[] = "-a-c-a 0-9 A-F o-t lalala ok hello world a-a --";
    char s2[BUF_SIZE];

    expand(s1, s2);

    printf("%s\n%s\n", s1, s2);

    return 0;
}
