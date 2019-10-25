#include <stdio.h>

#define TRUE (1==1)
#define FALSE (!TRUE)

int main(void) {
    int c, prev_is_ws;

    prev_is_ws = TRUE;

    while ((c = getchar()) != EOF) {
        // Assuming these are the "whitespace" separators we are concerned about
        if (c == ' ' || c == '\t' || c == '\n') {
            if (!prev_is_ws) {
                putchar('\n');
            }
            prev_is_ws = TRUE;
        } else {
            putchar(c);
            prev_is_ws = FALSE;
        }
    }

    return 0;
}
