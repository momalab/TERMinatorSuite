#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ROUNDS 22
#define KEY_LEN 4

#define ROR(x, r) ((x >> r) | (x << ((sizeof(uint16_t) * 8) - r)))
#define ROL(x, r) ((x << r) | (x >> ((sizeof(uint16_t) * 8) - r)))
#define R(x, y, k) (x = ROR(x, 7), x += y, x ^= k, y = ROL(y, 2), y ^= x)

void speck_expand(uint16_t const K[static KEY_LEN], uint16_t S[static ROUNDS]) {
    uint16_t b = K[0];
    uint16_t a[KEY_LEN - 1];
    for (int i = 0; i < KEY_LEN - 1 ; i++) {
        a[i] = K[i + 1];
    }
    S[0] = b;  
    for (int i = 0; i < ROUNDS - 1; i++) {
        R(a[i % (KEY_LEN - 1)], b, i);
        S[i + 1] = b;
    }
}

int main(void) {
    const uint16_t key[4] = { 256, 2312, 4368, 6424 };
    uint16_t exp[ROUNDS];
    speck_expand(key, exp);

    for (int i = 0; i < ROUNDS; ++i) {
        printf("%zu ", exp[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
