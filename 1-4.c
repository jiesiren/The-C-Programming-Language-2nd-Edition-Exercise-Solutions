#include <stdio.h>

int main(void) {
  float fahr, celsius;
  int lower, upper, step;

  lower = -40;
  upper = 110;
  step = 10;

  // 4 and 7 since º (\u00BA) apparently takes up 2 char spots
  printf("%4s %7s\n", "\u00BAC", "\u00BAF");

  celsius = lower;
  while (celsius <= upper) {
    fahr = ((9.0 / 5.0) * celsius) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
  return 0;
}
