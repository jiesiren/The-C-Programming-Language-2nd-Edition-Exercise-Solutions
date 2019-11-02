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

void itoa(int n, char s[]) {
    int sign = (n < 0) ? -1 : 1;
    int i = 0;

    do {
        s[i++] = (sign * (n % 10)) + '0';
    } while (n /= 10);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

int main(void) {
    /*
    The initial version of itoa does not work on the largest negative number
    because when the number is negated "n = -n;", it becomes itself. Since
    the largest negative number is in the form of 100...00 - all zeros except
    the leftmost/sign bit, taking the two's complement (flipping all the bits
    then adding 1) results in the same number. Thus we need to handle this
    unique case separately.
    */

    char s[BUF_SIZE];
    int n = ~(~0U >> 1);

    itoa(n, s);

    printf("num  = %d\n", n);
    printf("itoa = %s\n", s);

    return 0;
}
