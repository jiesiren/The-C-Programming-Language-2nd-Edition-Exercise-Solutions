#include <stdio.h>

#define TAB_SIZE 4

// Note: Lol did not interpret question correctly first time, so here
// is an extra function that converts tabs to spaces ¯\_(ツ)_/¯
// buf_size is the size of the provided char array line
/*
void tab_to_spaces_line(char line[], int buf_size) {
    int i = 0;
    int num_tabs = 0;

    while (line[i] != '\0') {
        if (line[i] == '\t') {
            num_tabs++;
        }
        i++;
    }

    if (!num_tabs) return;

    int chars_to_add = num_tabs * (SPACES_PER_TAB - 1);
    if ((i + chars_to_add) > buf_size) {
        printf("Skipping line since string buffer not big enough for transformation.\n");
        return;
    }

    int j = i + chars_to_add;
    while (i >= 0) {
        if (line[i] == '\t') {
            // insert spaces instead of copying tab
            for (int k = 0; k < SPACES_PER_TAB; k++) {
                line[j] = ' ';
                j--;
            }
        } else {
            line[j] = line[i];
            j--;
        }
        i--;
    }
}
*/

int main(void) {
    int c, i;

    i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            do {
                i = (i + 1) % TAB_SIZE;
                putchar(' ');
            } while (i != 0);
        } else {
            if (c == '\n') {
                i = 0;
            } else {
                i = (i + 1) % TAB_SIZE;
            }
            putchar(c);
        }
    }

    return 0;
}
