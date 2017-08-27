### Matrices Multiplication

Given two integer matrices as input, for example:
```
A=
1 2 3
4 5 6
```
and
```
B=
1 2 3 4
4 4 3 2 
9 7 6 4
```
compute the product AB of the inputs and return the result: 
```
AxB=
36 31 27 20
78 70 63 50
```

**Open values:** The matrix dimensions (i.e., ```row1 col1 row2 col2```, which is defined in [header.opn](https://github.com/momalab/privacy_benchmarks/tree/master/matrixMultiplication/header.opn)).

**Encrypted Values:** The contents of both input matrices, and the output matrix.

**Result:** The output matrix has dimensions ```row1 * col2``` (assuming `col1 = row2`). The dimisions of the output are not encrypted.

**The source code of this benchmark is available both in `C` as well as `CEAL` (`.sca`) format. In CEAL, `_o.sca` denotes a program without privacy protections, while `_s.sca` denotes a privacy-preserving program. Moreover, `.opn` denotes an unencrypted input database file, while `.sec` denotes an encrypted input database file.**

CEAL Benchmark Evaluation
-------------------------
![alt text](./../graphs/mmult.png)
