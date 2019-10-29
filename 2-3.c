#include <stdio.h>

#define BUF_SIZE 1000

int str_len(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int htoi(const char s[]) {
    int cur_i = str_len(s) - 1;
    int end_i = 0;

    // Skip optional prefix "0x" or "0X" denoting hex
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        end_i = 2;
    }

    int total_value = 0;
    int pos_value = 1;
    while (cur_i >= end_i) {
        const char c = s[cur_i];
        int digit_value;
        if (c >= '0' && c <= '9') {
            digit_value = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit_value = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            digit_value = c - 'A' + 10;
        } else {
            printf("%s is not a valid hex value!\n", s);
            return 0;
        }
        total_value += digit_value * pos_value;
        pos_value *= 16;
        cur_i--;
    }

    return total_value;
}

int main(void) {
    char s[BUF_SIZE];
    int i = 0;

    // Read input until EOF or newline
    while (i < BUF_SIZE - 1 && (s[i] = getchar()) != EOF && s[i] != '\n') {
        i++;
    }
    s[i] = '\0';

    printf("%s =\n%d\n", s, htoi(s));

    return 0;
}
