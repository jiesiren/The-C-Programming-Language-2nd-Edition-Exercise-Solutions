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

int any(char s1[], char s2[]) {
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

    for (int i = 0; s1[i] != '\0'; i++) {
        if (get_bit(c_bf, s1[i])) {
            return i;
        }
    }

    return -1;
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

    printf("s1 = '%s'\n", s1);
    printf("s2 = '%s'\n", s2);
    printf("The first occurence of any characters from s2 in s1 occurs at index %d\n", any(s1, s2));

    return 0;
}
