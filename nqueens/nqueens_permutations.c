#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <inttypes.h>

#define BOARD_SIZE 4
int sol_cnt = 0;

int gfun(int x, int y) {
    return (x <= 0) ? 0 : y;
}

void decodeSols(uint64_t **all_sols, int size, int sol_num) {
    for (int sol = 1 ; sol <= sol_num ; sol++) {
        for (int i = 0 ; i < size ; i++) {
            for (int j = 0 ; j < size ; j++) {
                if (all_sols[i][j] & (((uint64_t)1) << sol))
                    printf("Q ");
                else
                    printf("_ ");
            }
            printf("\n");
        }
        printf("\n");
    }
}

void encodeSol(uint64_t **all_sols, int **solution, int size, int sol_num, int safe) {
    for (int i = 0 ; i < size ; i++) {
        for (int j = 0 ; j < size ; j++) {
            all_sols[i][j] += ((((uint64_t)1) << sol_num) * solution[i][j]) * safe;
        }
    }
}

int colsSafe(int **board, int size) {
    int safe = 1;
    for (int j = 0 ; j < size ; j++) {
        int cols_sum = 0;
        for (int i = 0 ; i < size ; i++) {
            cols_sum += board[i][j];
        }
        safe = safe * cols_sum;
    }
    return gfun(safe, 1);
}

int diagsSafe(int **board, int size) {
    int not_safe_p = 0, not_safe_s = 0;
    for (int k = 0 ; k < size * 2 ; k++) {
        int p_sum = 0; // primary diagonals sum
        int s_sum = 0; // secondary diagonals sum
        for (int j = 0 ; j <= k ; j++) {
            int i = k - j;
            int jj = size-1 - j; // secondary
            if (i < size && j < size) {
                s_sum += board[i][jj];
                p_sum += board[i][j];
            }
        }
        not_safe_s += gfun(s_sum-1, 1);
        not_safe_p += gfun(p_sum-1, 1);
    }
    return gfun(1-not_safe_p, 1) * gfun(1-not_safe_s, 1);
}

void permuteRows(uint64_t **all_sols, int **array, int depth) {
    if (depth == BOARD_SIZE) {
        int is_safe = colsSafe(array, BOARD_SIZE) && diagsSafe(array, BOARD_SIZE);
        sol_cnt += is_safe;
        encodeSol(all_sols, array, BOARD_SIZE, sol_cnt, is_safe);
        return;
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        permuteRows(all_sols, array, depth+1);
        array[depth][i] = 0;
        array[depth][(i + 1) * (i != BOARD_SIZE-1)] = 1; // array[depth][(i+1) % BOARD_SIZE] = 1;
    }
}

int main(void) {
    int **array = malloc(BOARD_SIZE * sizeof(int *));
    uint64_t **all_sols = malloc(BOARD_SIZE * sizeof(uint64_t *));
    for (int i = 0 ; i < BOARD_SIZE ; i++) {
        array[i] = calloc(BOARD_SIZE, sizeof(int));
        all_sols[i] = calloc(BOARD_SIZE, sizeof(uint64_t));
        for (int j = 0 ; j < BOARD_SIZE ; j++) {
            array[i][j] = j == 0;
        }
    }
    
    permuteRows(all_sols, array, 0);
    
    decodeSols(all_sols, BOARD_SIZE, sol_cnt);
    for (int i ; i < BOARD_SIZE ; i++) {
        for (int j = 0 ; j < BOARD_SIZE ; j++) {
            printf("%" PRIu64 " ", all_sols[i][j]);
        }
        printf("\n");
    } 
    printf("%d-Queens have %d solutions\n", BOARD_SIZE, sol_cnt);
    return 0;
}
