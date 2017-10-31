#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void printArray(int *array, int size) {
    for (int i = 0 ; i < size ; i++)
        printf("%d", array[i]);
    printf("\n");
}

void permute(int *array, int size, int l, int r) {
    if (l == r) {
        printArray(array, size);
    } else {
        for (int i = l; i <= r; i++) {
            swap((array+l), (array+i)); // swap
            permute(array, size, l+1, r);
            swap((array+l), (array+i)); // restore the swap
        }
    }
}

int main(void) {
    int array[3] = { 1, 2, 3 };
    int n = sizeof(array) / sizeof(int);
    permute(array, n, 0, n-1);
    return 0;
}
