#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define X 9999

/************************************************************
** Set intersection without Branches on Encrypted values
*************************************************************
************************************************************************************************
** For every element in the first set, check every element in the second. 
** Return an set of the same size. The two sets must have equal sizes. If not, the smallest 
** should be padded with X's.
***********************************************************************************************/

int* intersect(int arr1[], int arr2[], int size) {
    int *res = calloc(size, sizeof(int));
    int *exist = calloc(size, sizeof(int));

    for (int i = 0; i < size ; i++) {
        for (int j = 0 ; j < size ; j++) {
            int eq = (arr1[i] == arr2[j]) ? 1 : 0;
            exist[i] += eq;
            res[i] += eq * arr1[i];
            arr1[i] += eq * X;
            arr2[j] += eq * X;
        }
    }
    for (int i = 0 ; i < size ; i++) {
        res[i] = (1-exist[i]) * X + exist[i] * res[i];
    }
    return res;
}

int main(void) {
    int arr1[10] = { 1, 1, 1, 2, 3, X, X, X, X, X };
    int arr2[10] = { 2, 2, 2, 1, 1, 1, 1, 1, 1, 1 };

    int m = sizeof(arr1) / sizeof(int);
    int n = sizeof(arr2) / sizeof(int);
    assert(m == n);
    int size = m;
    int *res = intersect(arr1, arr2, size);
    for (int i = 0 ; i < size ; i++)
        if (res[i] == X)
            printf("X  ");
        else
            printf("%d  ", res[i]);
    printf("\n");

    return 0;
}
