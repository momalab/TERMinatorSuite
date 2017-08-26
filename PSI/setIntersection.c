#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define epsilon 9999

/************************************************************
** Set intersection without Branches on Encrypted values
*************************************************************
************************************************************************************************
** For every element in the first set, check every element in the second. 
** Return an set of the same size. The two sets must have equal sizes. If not, the smallest 
** should be padded with epsilon's.
***********************************************************************************************/

int* intersect(int set1[], int set2[], int size) {
    int *res = calloc(size, sizeof(int));               // allocate memory for the set intersection
    int *exist = calloc(size, sizeof(int));             // for each position of the first set count equalities found in the second set

    for (int i = 0; i < size ; i++) {                   // for each item in set1
        for (int j = 0 ; j < size ; j++) {              // for each item in set2
            int eq = (set1[i] == set2[j]) ? 1 : 0;      // check equality
            exist[i] += eq;                             // mark index i of the first set as matched
            res[i] += eq * set1[i];                     // if equal add it to the result
            set1[i] += eq * epsilon;                          // mark i as visited if found equal
            set2[j] += eq * epsilon;                          // mark j as visited if found equal
        }
    }
    for (int i = 0 ; i < size ; i++) {
        res[i] = (1-exist[i]) * epsilon + exist[i] * res[i];  // Keep result[i] if exists[i] == 1, else mark it as NULL 
    }
    return res;
}

// A simple main to demonstrate the Private Set Intersection
int main(void) {
    int set1[10] = { 1, 1, 1, 2, 3, epsilon, epsilon, epsilon, epsilon, epsilon };
    int set2[10] = { 2, 2, 2, 1, 1, 1, 1, 1, 1, 1 };

    int m = sizeof(set1) / sizeof(int);
    int n = sizeof(set2) / sizeof(int);
    assert(m == n);
    int size = m;
    int *res = intersect(set1, set2, size);
    for (int i = 0 ; i < size ; i++)
        if (res[i] == epsilon)
            printf("epsilon  ");
        else
            printf("%d  ", res[i]);
    printf("\n");

    return 0;
}
