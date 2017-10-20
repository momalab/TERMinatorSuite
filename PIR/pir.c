#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // odd positions are keys, even are values
    int kv_array[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    int size = sizeof(kv_array)/sizeof(int);

    int enc_input = 7;

    int sum = 0;
    for (int i = 0 ; i < size ; i+=2) {
        int key = kv_array[i];
        int val = kv_array[i+1];

        sum += (key == enc_input) * val;    
    }

    printf("Encrypted key %d has value %d\n", enc_input, sum);

    return 0;
}