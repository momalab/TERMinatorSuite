#include <stdio.h>
#include <stdlib.h>

#define epsilon 9999

/**************************************************************
** Array Deduplication: Keep unique occurrences of each object
***************************************************************
************************************************************************************************
** For every element in the array, check every element after it. 
** Replace all duplicates with epsilon
***********************************************************************************************/

void deduplication(int array[], int size) {
    for (int i = 0; i < size ; i++) {                       // for each item in set1
        for (int j = i+1 ; j < size ; j++) {                // for each item in set2
            int eq = (array[i] == array[j]) ? 1 : 0;        // if (array[i] == array[j]) { array[j] = epsilon; }
            array[j] = eq * epsilon + (1-eq) * array[j];    // else { array[j] = array[j]; }
        }
    }
}

// A simple main to demonstrate the data Deduplication
int main(void) {
    int array[10] = { 1, 1, 1, 2, 3, 3, 4, 5, 5, 6 };
    int size = sizeof(array) / sizeof(int);

    deduplication(array, size);
    for (int i = 0 ; i < size ; i++)
        if (array[i] == epsilon)
            printf("epsilon  ");
        else
            printf("%d  ", array[i]);
    printf("\n");

    return 0;
}
