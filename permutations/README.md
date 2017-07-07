### Permutations
The notion of permutation relates to the act of arranging all the members of a set into some sequence or order, or if the set is already ordered, rearranging its elements, a process called permuting. This benchmark, computes and prints all permutations of a given array/set.

**Open value:** We cannot protect the size of the input/given array.

**Encrypted Values:** We are protecting the contents of the input, as well as all the output/permuted arrays.

**Result:** All possible permutations of the input array.

**Recursion:** Cryptoleq does not have "native" recursion; but it can provide a large amount of memory to simulate recursion. In order to do so, before every recursive call (```goto to the beginning```) we must store all local variables into a stack, and respectively after returning from a recursive call we must unstack the stored local variables.

[Encrypted Numbers](https://github.com/momalab/privacy_benchmarks/tree/master/permutations/permutations_s.sca)
