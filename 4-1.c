#include <stdio.h>

int str_len(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int strrindex(char s[], char t[]) {
    int t_len = str_len(t);
    int s_len = str_len(s);

    if (!t_len || t_len > s_len) {
        return -1;
    }

    for (int i = s_len - 1; i >= 0; i--) {
        int j = 0;
        while (j < t_len && (i - j) >= 0
                && s[i - j] == t[t_len - 1 - j]) {
            j++;
        }

        if (j == t_len) {
            return i - j + 1;
        }
    }

    return -1;
}

int main(void) {
    char s[] = "hello my name is cat";
    char t[] = "t";

    printf("s = %s\n", s);
    printf("t = %s\n", t);
    printf("strrindex(s, t) = %d\n", strrindex(s, t));

    return 0;
}
