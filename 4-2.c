#include <stdio.h>
#include <ctype.h>

double atof(char s[]) {
    double val, power;
    int i, sign;

    // skip spaces
    for (i = 0; isspace(s[i]); i++);

    // read and skip optional sign
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') i++;

    // read integer part
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    // skip decimal char
    if (s[i] == '.') i++;

    // read decimal part
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // compute value so far without scientific notation part
    val = sign * val / power;

    // skip scientific notation part
    if (s[i] == 'e' || s[i] == 'E') i++;

    // read and skip optional sign
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') i++;

    // read scientific notation exponent
    int exp;
    for (exp = 0; isdigit(s[i]); i++) {
        exp = 10 * exp + (s[i] - '0');
    }

    // compute scientific notation exponent with base (10)
    for (power = 1.0; exp > 0; exp--) {
        if (sign > 0) {
            power *= 10.0;
        } else {
            power /= 10.0;
        }
    }

    return val * power;
}

int main(void) {
    char s[] = "123.45e-6";

    printf("s = %s\n", s);
    printf("atof(s) = %f\n", atof(s));
    printf("%f\n", 123.45e-6);

    return 0;
}
