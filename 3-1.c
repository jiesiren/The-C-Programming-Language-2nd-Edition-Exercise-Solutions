#include <stdio.h>
#include <time.h>

#define MAX_ELEMENT 100000
#define NUM_ITER 10000000

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + ((high - low) / 2);
        if (x > v[mid]) {
            low = mid + 1;
        } else if (x < v[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

/* binsearch2: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = low + ((high - low) / 2);

    while (low <= high && v[mid] != x) {
        if (x > v[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = low + ((high - low) / 2);
    }

    if (mid >= 0 && mid <= n - 1 && v[mid] == x) {
        return mid;
    } else {
        return -1;
    }
}

int main(void) {
    int v[MAX_ELEMENT];

    // init test data with ordered numbers
    for (int i = 0; i < MAX_ELEMENT; i++) {
        v[i] = i;
    }

    clock_t begin;
    double time_taken_s;

    begin = clock();
    for (int i = 0; i < NUM_ITER; i++) {
        binsearch(MAX_ELEMENT, v, MAX_ELEMENT);
    }
    time_taken_s = ((double) (clock() - begin)) / CLOCKS_PER_SEC;
    printf("binsearch time taken: %.4fs\n", time_taken_s);

    begin = clock();
    for (int i = 0; i < NUM_ITER; i++) {
        binsearch2(MAX_ELEMENT, v, MAX_ELEMENT);
    }
    time_taken_s = ((double) (clock() - begin)) / CLOCKS_PER_SEC;
    printf("binsearch2 time taken: %.4fs\n", time_taken_s);

    return 0;
}
