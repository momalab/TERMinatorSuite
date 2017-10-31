### N-Queens

The N-Queens benchamrk uses backtracking when the current queen placement hypothesis does not constitute a valid solution. Our threat model requires that the queen positions (the board state) is encrypted; this requirement, however, introduces termination problems as it is no longer possible to check if the placement hypothesis is safe or not.

To address termination challenges, this benchmark uses recursion to evaluate all possible queen placements, given that each chessboard row should have exactly one queen. At first, the algorithm initializes all queens on the first column of the chessboard (represented as a square matrix), and recursively permutes the queen position in each row, so that all rows are processed. At the maximum recursion depth, the algorithm validates if the chessboard state is safe by counting the queens in each column and each diagonal. 


```
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
        array[depth][(i+1) % BOARD_SIZE] = 1;
    }
}
```

To encode the correct solutions, the algorithm uses 2D solutions array, that has the same dimensions as the chessboard, but each array element can be large binary number. Each binary number in the solutions array is initialized to zero. At runtime, when the algorithm finds a the `i`-th solution, the encoding routine sets the `i`-th bit of the binary number at cell located at the array position where a queen should be. 

```
void encodeSol(uint64_t **all_sols, int **solution, int size, int sol_num, int safe) {
    for (int i = 0 ; i < size ; i++) {
        for (int j = 0 ; j < size ; j++) {
            all_sols[i][j] += ((((uint64_t)1) << sol_num) * solution[i][j]) * safe;
        }
    }
}
```

For example, the final encoded array of the 4-queens problem is (using decinals): 
```
0 2 4 0 
4 0 0 2 
2 0 0 4 
0 4 2 0
```
which is decoded to the following solutions:
```
_ Q _ _     _ _ Q _ 
_ _ _ Q     Q _ _ _ 
Q _ _ _     _ _ _ Q 
_ _ Q _     _ Q _ _ 

```

**The source code of this benchmark is available both in `C` as well as `CEAL` (`.sca`) format. In CEAL, `_s.sca` denotes a privacy-preserving program. The program `decode.py` is used to reverse the encoding presented above. The Cryptoleq architecture supports branching oracles, such as function G, and `CEAL` can invoke this function natively using `._G`. For architectures that do not support branching oracles natively, the `.c` source code simulates this functionality by defining `int gfun(int, int)`.**

CEAL Benchmark Evaluation
-------------------------
![alt text](./../graphs/nqueens.png)
