#include <stdio.h>
#include <limits.h>

#define BUF_SIZE 1000
#define BITS_IN_CHAR (sizeof(char) * CHAR_BIT)
// Number of "char"s to store a bit field for all values a "char" can take up
#define BFIELD_NCHARS (1 << (BITS_IN_CHAR - 1))

// sets the corresponding bit in char bit field c_bf for char c to 1
void set_bit(char c_bf[], char c) {
    c_bf[c / BITS_IN_CHAR] |= (1 << (c % BITS_IN_CHAR));
}

// returns 1 if the corresponding bit in char bit field c_bf for char c is 1, 0 otherwise
char get_bit(char c_bf[], char c) {
    return (c_bf[c / BITS_IN_CHAR] >> (c % BITS_IN_CHAR)) & 1;
}

// deletes each character in s1 that matches any character in the string s2
void squeeze(char s1[], char s2[]) {
    // bit field for all possible chars, init with chars in s2 enabled
    char c_bf[BFIELD_NCHARS];
    // initialize bit field to 0
    for (int k = 0; k < BFIELD_NCHARS; k++) {
        c_bf[k] = 0;
    }
    for (int k = 0; s2[k] != '\0'; k++) {
        // set corresponding bit for s2[k] to 1
        set_bit(c_bf, s2[k]);
    }

    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        // copy over char if not in s2
        if (!get_bit(c_bf, s1[i])) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main(void) {
    char s1[BUF_SIZE];
    char s2[BUF_SIZE];
    int i = 0;

    // read in s1
    while (i < BUF_SIZE - 1 && (s1[i] = getchar()) != '\n') {
        i++;
    }
    s1[i] = '\0';
    i = 0;

    // read in s2
    while (i < BUF_SIZE - 1 && (s2[i] = getchar()) != EOF && s2[i] != '\n') {
        i++;
    }
    s2[i] = '\0';

    squeeze(s1, s2);

    printf("%s\n", s1);

    return 0;
}
