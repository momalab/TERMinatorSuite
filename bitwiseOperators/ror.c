#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <assert.h>

#define WORD_SIZE 32

#define ROR(x, r) ((x >> r) | (x << (WORD_SIZE - r)))

uint32_t ror_1(uint32_t x) {
    int lsb = x - (x/2) - (x/2);
    uint32_t y = lsb;
    for (int i = 0 ; i < WORD_SIZE-1 ; i++) {
        y += y;
    }
    x = (x-lsb)/2;
    y += x;
    return y;
}

uint32_t ror_n(uint32_t x, int   n) {
    for (int i = 0 ; i < n ; i++) {
        x = ror_1(x);
    }
    return x;
}

int main(void) {
    srand((unsigned) time(NULL));
    for (int i = 0 ; i < 100 ; i++) {
        int x = rand() % 1024;
        int n = rand() % 30;
        assert(ROR(x, n) == ror_n(x, n));
    }
    return 0;
}
