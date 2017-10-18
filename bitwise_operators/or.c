#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int G(int x, int y) {
    return (x <= 0) ? 0 : y;
}

//Bitwise OR function
int or(int x,int y,int length){
    int i;
    int sum = 0; 
    int accum = 1;
    for(i=0; i<length; i++){
        sum += ((((x/accum)%2)+((y/accum)%2) <= 0) ? 0 : 1) * accum;
        accum = accum*2;
    }
    return sum;
}

// Bitwise OR function
int or_ll(int x, int y, int length){
    int i;
    int x_or_y = 0; 
    int x_half, y_half, lsb_x, lsb_y, lsb;
    for (i = 0; i < length ; i++){
        // Compute LSB(x)
        x_half = x / 2;
        lsb_x = x - (x_half + x_half);

        // Compute LSB(y)
        y_half = y / 2;
        lsb_y = y - (y_half + y_half);

        // Compute LSB(x) OR LSB(y)
        lsb = G(lsb_x + lsb_y, 1);

        // Sum up
        int exp_result = lsb;   // x_or_y += lsb << i;
        for (int j = 0 ; j < i ; j++) { 
            exp_result *= 2;
        }
        x_or_y += exp_result;

        // Continue with next bits
        x >>= 1;
        y >>= 1;
    }
    return x_or_y;
}

int main(void) {
    srand((unsigned) time (NULL));
    for (int i = 0 ; i < 20; i++) {
        int x = rand() % 16;
        int y = rand() % 16;
        assert((x | y) == or_ll(x, y, 4));
        assert((x | y) == or(x, y, 4));
        printf("%d | %d = %d\n", x, y, x|y);
    }
    return 0;
}
