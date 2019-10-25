#include <stdio.h>

#define BUFFER_SIZE 1000
#define TAB_STOP_SIZE 4
#define SPACES_PER_TAB 4

int get_line(char s[], int buf_size) {
    int c, i;

    for (i = 0; i < buf_size - 1
            && (c = getchar()) != EOF
            && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void detab_line(char line[], int buf_size) {
    int i = 0;
    int chars_to_add = 0; // in addition to replacing the '\t' char
    while (line[i]) {
        if (line[i] == '\t') {
            int spaces_needed = i % TAB_STOP_SIZE;
            if (spaces_needed == 0) {
                spaces_needed = TAB_STOP_SIZE;
            }

        }
    }
}

// Note: Lol did not interpret question correctly first time, so here
// is an extra function that converts tabs to spaces ¯\_(ツ)_/¯
// buf_size is the size of the provided char array line
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

int main() {
    int len;
    char line[BUFFER_SIZE];

    while ((len = get_line(line, BUFFER_SIZE)) > 0) {
        detab_line(line, BUFFER_SIZE);
        tab_to_spaces_line(line, BUFFER_SIZE);
        printf("%s", line);
    }
}