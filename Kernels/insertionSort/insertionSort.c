/* insertion sort ascending order */
#include <stdio.h>
 
int gfun(int x, int y) {
    return (x <= 0) ? 0 : y;
}

int main(void) {
    int array[10] = { 4, 2, 5, 9, 1, 0, 4, 3, 9, 8 };

    int N = sizeof(array) / sizeof(array[0]);               // get size of array
    int i, j;
    for (i = 1 ; i < N; i++) {
        j = i;
        while (j != 0) {
            int x = array[j-1];
            int y = array[j];

            int diff = gfun(x-y, x-y) + gfun(y-x, y-x);     // compute |x-y|
            int max = gfun(x-y, x) + gfun(y-x, y);          // compute max(x, y)
            max += (x == y) * x;                            // if x == y set max to x
            int min = max - diff;                           // compute min 

            // swap in ascending order 
            array[j-1] = min;                               
            array[j] = max;
            j--;
        }
    }

    for (i = 0; i < N; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
