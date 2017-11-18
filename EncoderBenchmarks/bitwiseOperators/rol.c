#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <assert.h>

#define WORD_SIZE 32

#define ROL(x, r) ((x << r) | (x >> (WORD_SIZE - r)))

uint32_t rol_1(uint32_t x) {
    uint32_t tmp = x;
    for (int i = 0 ; i < WORD_SIZE-1 ; i++) {
        int lsb = x - (x/2) - (x/2);
        x=(x-lsb)/2;
    }
    int msb = x;
    for (int i = 0 ; i < WORD_SIZE-1 ; i++) {
        x += x;
    }
    return (tmp - x) + (tmp - x) + msb;
}

uint32_t rol_n(uint32_t x, int   n) {
    for (int i = 0 ; i < n ; i++) {
        x = rol_1(x);
    }
    return x;
}

int main(void) {
    srand((unsigned) time(NULL));
    for (int i = 0 ; i < 100 ; i++) {
        int x = rand() % 1024;
        int n = rand() % 30;
        assert(ROL(x, n) == rol_n(x, n));
    }
    return 0;
}
