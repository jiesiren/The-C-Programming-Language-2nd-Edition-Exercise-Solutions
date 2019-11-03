#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main(void) {
    int type, i_op2;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: / zero divisor\n");
                }
                break;
            case '%':
                i_op2 = pop();
                if (i_op2 != 0) {
                    push((int) pop() % i_op2);
                } else {
                    printf("error: %% zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

#define STACK_DEPTH 100

int sp = 0;
double stack[STACK_DEPTH];

void push(double f) {
    if (sp < STACK_DEPTH) {
        stack[sp++] = f;
    } else {
        printf("error: stack full, can't push again %g\n", f);
    }
}

double pop(void) {
    if (sp > 0) {
        return stack[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;

    // skip spaces and tabs
    while ((s[0] = c = getch()) == ' ' || c == '\t');

    // s[0] should have the first non-whitespace char
    s[1] = '\0';

    i = 0;

    // if '-' and immediately followed by a digit or '.'
    // it is a negative number, read in that digit/'.'
    if (c == '-') {
        c = getch();
        if (isdigit(c) || c == '.') {
            s[1] = c;
            i = 1;
        } else {
            ungetch(c);
            c = '-';
        }
    }

    // return op if not a number
    if (!isdigit(c) && c != '.') {
        return c;
    }

    // read in integer part of number
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }

    // read in fraction part if decimal
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: buffer full, too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
