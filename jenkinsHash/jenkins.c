#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t jenkins_one_at_a_time_hash(const uint8_t* key, size_t length) {
    size_t i = 0;
    uint32_t hash = 0;
    while (i != length) {
        hash += key[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}

int main(void) {
    size_t length = 4;
    uint8_t* array = malloc(length * sizeof(uint8_t));
    for (int i = 0 ; i < length ; i++) {
        array[i] = i + 1;
    }

    printf("hash : %zu\n", jenkins_one_at_a_time_hash(array, length));

    return 0;
}
