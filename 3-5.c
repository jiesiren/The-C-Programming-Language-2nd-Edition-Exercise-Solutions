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

char cinb(int offset) {
    printf("offset: %d\n", offset);
    if (offset < 10) {
        return offset + '0';
    } else if (offset < 16) {
        return (offset - 10) + 'a';
    } else {
        return '!';
    }
}

void itob(int n, char s[], int b) {
    if (!(b >= 2 && b <= 16)) {
        printf("Base must be between 2 and 16.\n");
        return;
    }
    int sign = (n < 0) ? -1 : 1;
    int i = 0;

    do {
        s[i++] = cinb(sign * (n % b));
    } while (n /= b);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

int main(void) {
    char s[BUF_SIZE];
    int n = -123;
    int b = 16;

    itob(n, s, b);

    printf("n = %d\n", n);
    printf("itob(%d, s, %d) = %s\n", n, b, s);

    return 0;
}
