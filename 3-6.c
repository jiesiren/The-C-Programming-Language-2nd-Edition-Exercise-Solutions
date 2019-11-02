#include <stdio.h>

#define BUF_SIZE 1000

void reverse(char s[]) {
    int i = 0, j = 0;

    while (s[j]) {
        j++;
    }
    j--;

    char tmp;
    while (i < j) {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
        i++;
        j--;
    }
}

void itoa(int n, char s[], int min_width) {
    int sign = (n < 0) ? -1 : 1;
    int i = 0;

    do {
        s[i++] = (sign * (n % 10)) + '0';
    } while (n /= 10);

    if (sign < 0) {
        s[i++] = '-';
    }

    // the only difference from exercise 3-4
    while (i < min_width) {
        s[i++] = ' ';
    }

    s[i] = '\0';

    reverse(s);
}

int main(void) {
    char s[BUF_SIZE];
    int n = ~(~0U >> 1);
    int min_width = 20;

    itoa(n, s, min_width);

    printf("num  = %d\n", n);
    printf("min_width = %d\n", min_width);
    printf("itoa = %s\n", s);

    return 0;
}
