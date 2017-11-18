#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define ROUNDS 22

#define ROR(x, r) ((x >> r) | (x << ((sizeof(uint16_t) * 8) - r)))
#define ROL(x, r) ((x << r) | (x >> ((sizeof(uint16_t) * 8) - r)))
#define R(x, y, k) (x = ROR(x, 7), x += y, x ^= k, y = ROL(y, 2), y ^= x)
#define RR(x, y, k) (y ^= x, y = ROR(y, 2), x ^= k, x -= y, x = ROL(x, 7))

void speck_encrypt(uint16_t const pt[static 2], uint16_t ct[static 2], uint16_t const K[static ROUNDS]) {
    ct[0] = pt[0];
    ct[1] = pt[1];
    for (int i = 0; i < ROUNDS; i++) {
        R(ct[1], ct[0], K[i]);
    }
}

/*
void speck_encrypt_ll(uint16_t const pt[static 2], uint16_t ct[static 2], uint16_t const K[static ROUNDS]) {
    uint16_t x = pt[0];
    uint16_t y = pt[1];
    printf("\n");
    for (int i = 0; i < ROUNDS; i++) {
        y = ROR(y, 7);
        y += x;
        y ^= K[i];
        x = ROR(x, 14);
        x ^= y;
        printf("%" PRIu16 " ", x);
    }
    printf("\n\n");
    ct[0] = x;
    ct[1] = y;
}
*/

void speck_decrypt(uint16_t const ct[static 2], uint16_t pt[static 2], uint16_t const K[static ROUNDS]) {
    pt[0] = ct[0];
    pt[1] = ct[1];
    for (int i = 0; i < ROUNDS; i++) {
        RR(pt[1], pt[0], K[(ROUNDS - 1) - i]);
    }
}

int main(void) {
    uint16_t plain_text[2] = { 26956, 25972 };
    uint16_t cipher_text[2] = { 17138, 43112 };

    uint16_t buffer[2] = { 0 };
    uint16_t exp[ROUNDS] = { 256, 5394, 24957, 5208, 26905, 30690, 3209, 52443, 61418, 20019, 30452, 22902, 61067, 56068, 17943, 62334, 34740, 36554, 60827, 14930, 33321, 60772 };

    printf("Plain text: %" PRIu16 " %" PRIu16 "\n\n", plain_text[0], plain_text[1]);
    printf("================== SPECK ENCRYPTION ==================\n");
    speck_encrypt(plain_text, buffer, exp);
    if (buffer[0] != cipher_text[0] || buffer[1] != cipher_text[1]) {
        printf("encryption failed\n");
        return EXIT_FAILURE;
    }
    printf("==> Cipher text: %" PRIu16 " %" PRIu16 "\n\n", buffer[0], buffer[1]);

    printf("================== SPECK DECRYPTION ==================\n");
    speck_decrypt(cipher_text, buffer, exp);
    if (buffer[0] != plain_text[0] || buffer[1] != plain_text[1]) {
        printf("decryption failed\n");
        return EXIT_FAILURE;
    }
    printf("==> Plain text: %" PRIu16 " %" PRIu16 " (decrypted cipher text)\n\n", buffer[0], buffer[1]);

    printf("Encryption and decryption success\n");
    return EXIT_SUCCESS;
}
