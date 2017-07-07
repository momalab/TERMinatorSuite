#include <stdio.h>
#include <assert.h>

#define MAX_NUM 8
#define ITERATIONS MAX_NUM-1

int tak(int x, int y, int z) {
    while (x > y) {
        int oldx = x, oldy = y;
        x = tak(x - 1, y, z);
        y = tak(y - 1, z, oldx);
        if (x <= y) 
            break;
        z = tak(z - 1, oldx, oldy);
    }
    return z;
}

int gfun(int x, int y) {
    return (x <= 0) ? 0 : y;
}

/*
 * Variable "iter" will not be encrypted
 */
int tak_unrolled(int x, int y, int z, int iter) {
    int sel = gfun(x-y, 1);     // sel = x > y;
    while (iter--) {
        int oldx = (1 - sel) * oldx + sel * x;
        int oldy = (1 - sel) * oldy + sel * y;
        x = (1 - sel) * x + sel * tak_unrolled(x - 1, y, z, iter);
        y = (1 - sel) * y + sel * tak_unrolled(y - 1, z, oldx, iter);
        sel = gfun(x-y, 1);     // sel = x > y;
        z = (1 - sel) * z + sel * tak_unrolled(z - 1, oldx, oldy, iter);
    }
    return z;
}

int main(void) {
    for (int i = 0 ; i <= MAX_NUM ; i++) {
        for (int j = 0 ; j <= MAX_NUM ; j++) {
            for (int k = 0 ; k <= MAX_NUM ; k++) {
                int x = tak(i, j, k);
                printf("%d %d %d : %d\n", i, j, k, x);
                assert(x == tak_unrolled(i, j, k, ITERATIONS));
            }
        }
    }
    return 0;
}

