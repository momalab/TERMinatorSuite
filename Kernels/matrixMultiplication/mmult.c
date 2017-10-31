/**************************************************
* MATRIX MULTIPLICATION: Steps from C to Assembly *
**************************************************/
#include <stdio.h>

void print1D(int *array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d ", array[i*cols + j]);
        printf("\n");
    }
    printf("\n\n");
}

void zero1D(int *array, int size) {
    for (int i = 0; i < size; ++i)
        array[i] = 0;
}

int main(void) {
    int i, j, k;
    int r1 = 2, c1 = 3, r2 = 3, c2 = 4;

/********************************************************************
** 2D Arrays
********************************************************************/
    int a1[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int b1[3][4] = { {1, 2, 3, 4}, {4, 4, 3, 2}, {9, 7, 6, 4 } };
    int result1[2][4] = { 0 };
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
                result1[i][j] += a1[i][k] * b1[k][j];
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j)
            printf("%d ", result1[i][j]);
        printf("\n");
    }
    printf("\n\n");

/********************************************************************
** 1D Arrays representing 2D Arrays
********************************************************************/
    int a2[2*3] = { 1, 2, 3, 4, 5, 6 };
    int b2[3*4] = { 1, 2, 3, 4, 4, 4, 3, 2, 9, 7, 6, 4 };
    int result2[2*4] = { 0 };

    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
                result2[i*c2 + j] += a2[i*c1 + k] * b2[k*c2 + j];
    print1D(result2, r1, c2);
    zero1D(result2, r1*c2);

/********************************************************************
** GoTo instead of for-loops
********************************************************************/
    int aa, bb;
    int *ptrA = a2;
    int *ptrB = b2;
    int *res = result2;
    int x, y, xytmp, xy;
    i = 0;
    outer1:
        j = 0;
        middle1:
            k = 0;
            inner1:
                x = *(ptrA + i*c1 + k);
                y = *(ptrB + k*c2 + j);
                xy = x*y;
                xytmp = *(res + i*c2 + j);
                *(res + i*c2 + j) = xytmp + xy;
                k++;
            if (k < c1) goto inner1;
            j++;
        if (j < c2) goto middle1;
        i++;
    if (i < r1) goto outer1;
    print1D(result2, r1, c2);
    zero1D(result2, r1*c2);

/********************************************************************
** pointer/label arithmetic instead of array[i*cols + j]
********************************************************************/
    i = 0;
    outer2:
        j = 0;
        middle2:
            k = 0;
            inner2:
                x = *ptrA;
                y = *ptrB;
                xy = x * y;
                *res += xy;

                k++;
                ptrA++;
                ptrB += c2;
            if (k < c1) goto inner2;
            j++;
            ptrA -= k;
            ptrB = b2 + j;
            res++;
        if (j < c2) goto middle2;
        i++;
        ptrA += c1;
        ptrB = b2;
        res += c2 - j;
    if (i < r1) goto outer2;
    print1D(result2, r1, c2);

/********************************************************************
** CEAL code in matrix_mult_o.sca
********************************************************************/   
    
    return 0;
}
