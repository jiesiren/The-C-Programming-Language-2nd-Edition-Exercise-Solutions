#include <stdio.h>

int main(void) {
    int c;
    int spaces, tabs, newlines;

    spaces = tabs = newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces++;
        } else if (c == '\t') {
            tabs++;
        } else if (c == '\n') {
            newlines++;
        }
    }

    printf("# spaces: %d\n", spaces);
    printf("# tabs: %d\n", tabs);
    printf("# newlines: %d\n", newlines);

    return 0;
}
