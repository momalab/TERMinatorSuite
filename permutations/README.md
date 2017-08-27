### Permutations
This benchmark computes and prints all permutations of a given array/set.

**Unencrypted value:** The size of the input array is not encrypted..

**Encrypted values:** All elements in the input array and in all permuted output arrays are encrypted.

**Result:** A set of all possible permutations of the input array.

**Recursion:** The CEAL language does not provide native support for recursion, but it is possible to simulate recursion by creating a stack construct in memory. For that matter, before a recursive call (i.e., ```goto to the beginning```), the CEAL program pushes all local variables in the stack. Likewise, as soon as control returns from a recursive call, the program pops all variables stored earlier.


![alt text](./../graphs/perm.png)
