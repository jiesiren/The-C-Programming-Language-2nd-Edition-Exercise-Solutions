#include <stdio.h>

float ftoc(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}

int main() {
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    // 4 and 7 since º (\u00BA) apparently takes up 2 char spots
    printf("%4s %7s\n", "\u00BAF", "\u00BAC");

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, ftoc(fahr));
        fahr = fahr + step;
    }
}
