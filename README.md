## TERMinator Suite
### Benchmarks for Privacy Preserving Architectures

#### Installation steps
Step 1: clone and set up the cryptoleq [repository](https://github.com/momalab/cryptoleq), as shown [here](https://github.com/momalab/cryptoleq/blob/master/doc/build_ceal.pdf):

```git clone https://github.com/momalab/cryptoleq.git```


Step 2: clone the benchmarks repository:

```git clone https://github.com/momalab/TERMinatorSuite.git```


Step 3: copy all the benchmark files inside the cryptoleq directory:

```cp -rf ./TERMinatorSuite/* ./cryptoleq/scr/ceal/tests/```



#### How to run a benchmark
Step 1: ensure that all benchmarks are inside the ```cryptoleq/scr/ceal/tests/``` directory. 

Step 2: ```cd``` to the benchmark you want to run (e.g., ```cd ./factorial```) and execute the following command:

```../../_bin_unx/ceal factorial_s.sca```

**Warning:** It is important to run each benchmark within its directory (as in the previous example), and not from the ```tests``` directory, since the ```ceal``` executable includes the ```lib``` folder from the parent directory.


#### TERMinator Suite Benchmarks

**All benchmarks are available as `C/C++` sources (`.c` files), as well as `CEAL` sources (`.sca` files). `CEAL` provides native support for a branching oracle (function G).** 

- __[Speck (cipher)](https://github.com/momalab/privacy_benchmarks/tree/master/SpeckCipher)__ [(link)](https://en.wikipedia.org/wiki/Speck_(cipher))
    * Speck is a family of lightweight block ciphers publicly released by the National Security Agency (NSA) in June 2013 ([Cryptology ePrint Archive](https://eprint.iacr.org/2013/404.pdf)). Speck has been optimized for performance in software implementations, while its sister algorithm, Simon, has been optimized for hardware implementations. Speck is an add-rotate-xor (ARX) cipher.
    * Speck uses a lot of bitwise operations (rotate-xor), which are not natively supported in encrypted computation architectures, like Cryptoleq. There is no actual access to the bits, since all data are encrypted. Thus, we use the [simulated bitwise operations](https://github.com/momalab/privacy_benchmarks/tree/master/bitwiseOperators) that TERMinator Suite provides.
    * __Threat Model:__ The key, the plaintext, and the ciphertext remain encrypted throughout the whole execution.


- __[Simon (cipher)](https://github.com/momalab/privacy_benchmarks/tree/master/SimonCipher)__ [(link)](https://en.wikipedia.org/wiki/Simon_(cipher))
    * Simon is a family of lightweight block ciphers publicly released by the National Security Agency (NSA) in June 2013 ([Cryptology ePrint Archive](https://eprint.iacr.org/2013/404.pdf)). Simon has been optimized for performance in hardware implementations, while its sister algorithm, Speck, has been optimized for software implementations. Simon is an add-rotate-xor (ARX) cipher.
    * Simon uses a lot of bitwise operations (rotate-and-xor), which are not natively supported in encrypted computation architectures, like Cryptoleq. There is no actual access to the bits, since all data are encrypted. Thus, we use the [simulated bitwise operations](https://github.com/momalab/privacy_benchmarks/tree/master/bitwiseOperators) that TERMinator Suite provides.
    * __Threat Model:__ The key, the plaintext, and the ciphertext remain encrypted throughout the whole execution.


- __[N-Queens](https://github.com/momalab/privacy_benchmarks/tree/master/nqueens)__ [(link)](http://www.kotesovec.cz/rivin_1994.pdf)
    * The 8-queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal. The N-Queens problem is the problem of placing N queens on an NxN chessboard.
    * __Threat Model:__ In this benchmark, the final solution needs to remain private, so all queen positions and intermediate values are encrypted. The only input is the number of the queens, which is defined as an open value.


- __[Tak function](https://github.com/momalab/privacy_benchmarks/tree/master/tak_function)__ [(link)](http://www.users.miamioh.edu/ishiut/papers/tarai_ipl.pdf)
    * The Tak function is a synthetic benchmark, often used to demonstrate recursion performance (named after Ikuo Takeuchi). It uses variables x, y and z as inputs, and unless x <= y, each invocation spawns three recursive calls, where each variable is reduced by one.
    * __Threat Model:__ Variables x, y and z are encrypted to preserve their privacy.


- __[Insertion-sort](https://github.com/momalab/privacy_benchmarks/tree/master/insertionSort)__ [(link)](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.45.8017&rep=rep1&type=pdf)
    * The insertion sort algorithm enables in-place sorting of an input array, by left-shifting each array element to its correct (sorted) position. The algorithm iterates over all array elements and compares the j-th element with its previous one; if the higher-index element is larger, the algorithm swaps the two elements. 
    * Performance:
        - Worst-case: О(n^2)
        - Average: О(n^2)
        - Best-case: O(n)
    * __Threat Model:__ In this benchmark, all elements of the input array are encrypted to protect their privacy. The size of the array is not encrypted.


- __[Set Intersection](https://github.com/momalab/privacy_benchmarks/tree/master/PSI)__ [(link)](https://www.cs.virginia.edu/~evans/pubs/ndss2012/psi.pdf)
    * Private set intersection allows two parties, holding sets A and B respectively, to compute all elements common to both A and B, without revealing any information about the non-common elements in the sets.
    * __Threat Model:__ In this benchmark, all input and output set elements are encrypted to preserve their privacy. The size of sets A and B is not encrypted. If one set is smaller, it is extended with copies of a null ciphertext (`epsilon`).


- __[Data Deduplication Algorithm](https://github.com/momalab/privacy_benchmarks/tree/master/deduplication)__ [(link)](https://en.wikipedia.org/wiki/Data_deduplication)
    * Data deduplication is a specialized data compression technique for eliminating duplicate copies of data.
    * __Threat Model:__ In this benchmark, all input and output array elements are encrypted to preserve their privacy. The size of input array is not encrypted. If the output array set is smaller (after removing same elements), it is extended with copies of a null ciphertext (`epsilon`).


- __Set Union__ [(link)](https://en.wikipedia.org/wiki/Union_(set_theory))
    * Private set union allows two parties, holding sets A and B respectively, to compute all elements that exist either in A, or in B, or in both of them, without revealing any information about the non-common elements in the sets.
    * __Threat Model:__ This benchmark shares the same threat model as the [Data Deduplication Algorithm](https://github.com/momalab/privacy_benchmarks/tree/master/Deduplication).
    * This is not a different benchmark, as it is based in the Data Deduplication benchmark. In order to compute the union of two sets, one should first concatenate the two sets, and then apply the Deduplication algorithm in order to remove duplicate objects.


- __[Fibonacci](https://github.com/momalab/privacy_benchmarks/tree/master/fibonacci)__ [(link)](http://mathworld.wolfram.com/FibonacciNumber.html)
    * The Fibonacci numbers form an integer sequence, where the first two integers (`F[1]` and `F[2]`)in the sequence are equal to `1`, and every other integer equals the sum of the two previous integers in the sequence: `F[n] = F[n-1] + F[n-2]`.
    * __Threat Model:__ The input integer `x` is encrypted to protect its privacy. This benchmark protects the input against information leakage from side channels.
    * This benchamark can compute up to a maximum input `N`. When the user input is `x`, for 0 <= x <= N, the program computes the corresponding Fibonacci output for every input in range [0, N] and obliviously selects `F[x]`. This is necessary to protect input `x` from side channel leakage, as the computation time of the algorithm is proportional to the user input `x`.


- __[Factorial](https://github.com/momalab/privacy_benchmarks/tree/master/factorial)__ [(link)](http://mathworld.wolfram.com/Factorial.html)
    * The factorial `n!` of a positive integer `n` is the product of all positive integers less than or equal to `n`. We also define `0!=1`.
    * __Threat Model:__ Similar to Fibonacci, the input integer `n` is encrypted to protect its privacy. This benchmark also protects against side channels.
    

- __[Matrix Multiplication](https://github.com/momalab/privacy_benchmarks/tree/master/matrixMultiplication)__ [(link)](http://mathworld.wolfram.com/MatrixMultiplication.html)
    * Matrix multiplication computes a new matrix that is the product of two input matrices A and B. If A is an ```n × m``` matrix and B is an ```m × p``` matrix, the product matrix C=AB is an ```n × p``` matrix, where `m` entries across a row of A are multiplied with the `m` entries down a column of B and accumulated to an element of C.
    * __Threat Model:__ In this benchmark, the contents of both input matrices, as well as the contents of the product matrix, are encrypted. The dimensions (```n m``` and ```m p```) are not encrypted.


- __[Permutations](https://github.com/momalab/privacy_benchmarks/tree/master/permutations)__ [(link)](http://mathworld.wolfram.com/Permutation.html)
    * This benchamark computes all possible permutations of the input set. A permutation is new potential arrangement in the order of a set. The total number of permutations in a set of `n` elements is the factorial `n!`.
    * __Threat Model:__ In this benchmark, we use encryption to protect the privacy of all elements in the input set, as well as all output sets (permutations). The cardinality of the input set is not protected.


- __[Sieve of Eratosthenes](https://github.com/momalab/privacy_benchmarks/tree/master/sieveOfEratosthenes)__ [(link)](http://mathworld.wolfram.com/SieveofEratosthenes.html)
    * This benchmark implements an algorithm for finding all prime numbers less than a maximum value. The benchmark iterates over all integers and marks as `composite` (i.e., not prime) all multiples of each prime, starting with the multiples of 2 (the first prime). This benchmark prints all prime numbers up to the input integer `n`.
    * __Threat Model:__ In this benchmark, we protect the privacy of all computed primes using encryption. In addition, this benchmark protects the cardinality of the output set, by also returning the encryption of zero for composites. The input integer `n` that determines the maximum prime is not encrypted.


- __[Prime Numbers](https://github.com/momalab/privacy_benchmarks/tree/master/prime_numbers)__ [(link)](http://mathworld.wolfram.com/PrimeNumber.html)
    * This benchmark uses the [Sieve of Eratosthenes](https://github.com/momalab/privacy_benchmarks/tree/master/sieveOfEratosthenes) algorithm to run indefinitely and generate each prime number in sequence.
    * __Threat Model:__  Similar to the Sieve of Eratosthenes, we protect the privacy of all computed primes. 


- __[Bitwise Operators](https://github.com/momalab/privacy_benchmarks/tree/master/bitwiseOperators)__ [(link)](https://en.wikipedia.org/wiki/Bitwise_operation)
    * Cryptoleq does not support natively bitwise operations. Thus we have simulated bitwise ```OR, AND, and XOR``` operations by iterating all bits of both numbers and by comparing the LSBs.
    * We have also added two more complex operators, ```ROR and ROL```, which are ROtate Right and Left respectively. Rotate operators are widely used in cryptographic block ciphers, like Speck and Simon.
    * __Threat Model:__ The word size (beta) is open, while the input and the output values are all encrypted.


- __[Jenkins one-at-a-time Hash Function](https://github.com/momalab/privacy_benchmarks/tree/master/jenkinsHash)__ [(link)](https://en.wikipedia.org/wiki/Jenkins_hash_function)
    * The Jenkins hash functions are a collection of (non-cryptographic) hash functions for multi-byte keys designed by Bob Jenkins.
    * Jenkins hash function uses a lot of bitwise operations, which are not natively supported in encrypted computation architectures, like Cryptoleq. There is no actual access to the bits, since all data are encrypted. Thus, we use the [simulated bitwise operations](https://github.com/momalab/privacy_benchmarks/tree/master/bitwiseOperators) that TERMinator Suite provides.
    * __Threat Model:__ The size of the array is unencrypted, while all the array elements and the output are encrypted.


- __[Private Information Retrieval](https://github.com/momalab/privacy_benchmarks/tree/master/PIR)__ [(link)](https://en.wikipedia.org/wiki/Private_information_retrieval)
    * Private Information Retrieval (PIR) is a classic example of applications which require private computation. In the simplest scenario, the user maintains an encrypted database on an untrusted server. At some point, the user desires to retrieve some data from the database, without revealing any information about the inquiry itself, data stored in the database or the result of the inquiry.
    * As a simple example, the database can be visualized as a table of key-value pair entries, e.g. {1:6, 2:7, 3:8, 4:9, 5:0, 6:1}. An inquiry to the database is a particular key and the expected output is the corresponding value. So, in this example, when the key 3 is requested the output returned to the user should be 8. As mentioned before, both the key input and the return result are encrypted. Therefore, PIR entails a brute-force search through all encrypted entries, secretly comparing database keys with the encrypted input, eventually returning the encrypted value when the keys match.
    * __Threat Model:__ The size of the encrypted database is unencrypted, while the input, the keys and the values are all encrypted.


- __[Number Occurrences](https://github.com/momalab/privacy_benchmarks/tree/master/numOccurrences)__
    * This benchmark receives a set of integers and computes the frequency that a specific test value occurs in the set.
    * __Threat Model:__ We protect the privacy of both the test value, as well as all elements in the input set using encryption.


#### `CEAL` Security Parameter (lambda) & Public Key (PQ)
The security parameter (lambda) represents the bit size of the public encryption key (PQ) of the Paillier cryptosystem. The public key is the product of two prime numbers (`P` and `Q`), and each such prime has a bitsize between  64 and 512 bits. As the security parameter size increases, the overall  performance of a benchmark is expected to decrease.

It is possible to change the security parameter of a benchmark by updating the ```.pragma PQ=``` directive at the beginning of a `CEAL` benchmark (```.sca``` file) with two prime numbers separated by a dot (`.`). The following are of public keys ranging from 16 to 1024 bits.

```
.pragma PQ=239.251
.pragma PQ=63199.64567
.pragma PQ=4281167959.4271299633
.pragma PQ=18299379327617480707.18345258783657292909
.pragma PQ=338871469111127928412308213206819656391.338531414912581056934822037249894061881
.pragma PQ=115689526107095890311249333520175779978137070980169508677335528535095435701957.115509443392406915656501893779637949187966713758992043305916442498716409678501
.pragma PQ=13392849694255970315601419090152597688339809774933571293865724091737666496951381207429127235940384883608845778583380210687006370486238723021460371010217257.13403952390292880134486926689236901739298695038033079040680862117777593853851234125818128702776151240584166261477766002390185782669746209391687589482784501
```
