#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

uint16_t jenkins_16b_ll(const uint16_t* key, size_t length) {
    size_t i = 0;
    uint32_t hash = 0;
    uint32_t temp;
    do {
        temp = key[i];
        i++;
        hash += temp;
        temp = hash << 10;
        temp &= 0xffff;
        hash += temp;
        temp = hash >> 6;
        hash ^= temp;
        printf(" %" PRIu32 "\n", hash);
    } while (i != length);
    temp = hash << 3;
    hash += temp;
    temp = hash >> 11;
    hash ^= temp;
    temp = hash << 15;
    temp &= 0xffff;
    hash += temp;
    hash &= 0xffff;
    return hash;
}

int main(void) {
    size_t length = 2;
    uint16_t* array = malloc(length * sizeof(uint16_t));
    array[0] = 24930; // ab
    array[1] = 25444; // cd
    printf("hash : %" PRIu32 "\n", jenkins_16b_ll(array, length));
    return 0;
}

// uint32_t jenkins_one_at_a_time_hash(const uint8_t* key, size_t length) {
//     size_t i = 0;
//     uint32_t hash = 0;
//     while (i != length) {
//         hash += key[i++];
//         hash += hash << 10;
//         hash ^= hash >> 6;
//     }
//     hash += hash << 3;
//     hash ^= hash >> 11;
//     hash += hash << 15;
//     return hash;
// }

