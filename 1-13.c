#include <stdio.h>

#define PLOT_CHAR '#'
#define MAX_LEN 20
// should be large enough for the num of digits in MAX_LEN provided above
#define COLUMN_SIZE 2

int main(void) {
    int c, cur_word_len;

    // counts[i] will contain the number of words of length i
    int counts[MAX_LEN];

    for (int i = 0; i < MAX_LEN; i++) {
        counts[i] = 0;
    }

    cur_word_len = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (cur_word_len != 0) {
                counts[cur_word_len]++;
                cur_word_len = 0;
            }
        } else {
            cur_word_len++;
        }
    }

    // Print horizontally
    for (int i = 0; i < MAX_LEN; i++) {
        if (counts[i] != 0) {
            printf("%d ", i);
            for (int j = 0; j < counts[i]; j++) {
                putchar(PLOT_CHAR);
            }
            putchar('\n');
        }
    }

    printf("\n\n");

    // Print vertically
    int max_count = 0;
    for (int i = 0; i < MAX_LEN; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
        }
    }
    for (int j = max_count; j > 0; j--) { // for each row (going down vertically)
        for (int i = 0; i < MAX_LEN; i++) {
            if (counts[i] != 0) {
                // Print plot symbol or not
                if (counts[i] >= j) {
                    putchar(PLOT_CHAR);
                } else {
                    putchar(' ');
                }
                // Fill rest of horizontal space up to COLUMN_SIZE + 1 extra space between
                for (int k = 0; k < COLUMN_SIZE; k++) {
                    putchar(' ');
                }
            }
        }
        printf("\n");
    }

    int num_printed;
    for (int i = 0; i < MAX_LEN; i++) {
        if (counts[i] != 0) {
            num_printed = printf("%d", i);
            // Fill rest of horizontal space up to COLUMN_SIZE + 1 extra space between
            for (int j = 0; j < (COLUMN_SIZE + 1 - num_printed); j++) {
                putchar(' ');
            }
        }
    }
    printf("\n");

    return 0;
}
