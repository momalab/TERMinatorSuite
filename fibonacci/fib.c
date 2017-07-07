#include <stdio.h>
 
#define MAX_NUM 50
#define NUM 12

int main(void) {
    int f1 = 0, f2 = 1, fi = 1;
    int i = 1;
    int result;
    do {
        result += (i == NUM) * fi;
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
    } while (++i != MAX_NUM);
    printf("fib(%d) = %d\n", NUM, result);
    return 0;
}
