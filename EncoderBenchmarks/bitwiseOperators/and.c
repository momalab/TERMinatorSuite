#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//Bitwise AND function
int and(int x,int y,int length){
    int i;
    int sum = 0; 
    int accum = 1;
    for(i=0; i<length; i++){
        sum += ((x/accum)%2)*((y/accum)%2)*accum;
        accum = accum*2;
    }
    return sum;
}

// Bitwise AND function
int and_ll(int x, int y, int length){
    int i;
    int x_and_y = 0; 
    int x_half, y_half, lsb_x, lsb_y, lsb;
    for (i = 0; i < length ; i++){
        // Compute LSB(x)
        x_half = x / 2;
        lsb_x = x - (x_half + x_half);

        // Compute LSB(y)
        y_half = y / 2;
        lsb_y = y - (y_half + y_half);

        // Compute LSB(x) AND LSB(y)
        lsb = (lsb_x * lsb_y);

        // Sum up
        int exp_result = lsb;   // x_and_y += lsb << i;
        for (int j = 0 ; j < i ; j++) { 
            exp_result *= 2;
        }
        x_and_y += exp_result;

        // Continue with next bits
        x >>= 1;
        y >>= 1;
    }
    return x_and_y;
}

int main(void) {
    srand((unsigned) time (NULL));
    for (int i = 0 ; i < 20; i++) {
        int x = rand() % 16;
        int y = rand() % 16;
        int res = and_ll(x, y, 4);
        assert(res == (x & y));
        assert(res == and(x, y, 4));
        printf("%d & %d = %d\n", x, y, res);
    }
    return 0;
}
