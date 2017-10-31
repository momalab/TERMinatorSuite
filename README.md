# TERMinator Suite
### Benchmarks for Privacy Preserving Architectures

Security and privacy are fundamental objectives characterizing contemporary cloud computing. Despite the wide adoption of encryption for protecting data in transit and at rest, data in use remains unencrypted inside cloud processors and memories, as computation is not applicable on encrypted values. This limitation introduces security risks, as unencrypted values can be leaked through side-channels or hardware Trojans. To address this problem, encrypted architectures have recently been proposed, which leverage homomorphic encryption to natively process encrypted data using datapaths of thousands of bits. In this case, additional security protections are traded for higher performance penalties, which drives the need for more efficient architectures. In this work, we develop benchmarks specifically tailored to encrypted computers, to enable comparisons across different architectures. Our benchmark suite, dubbed TERMinator, is unique as it avoids `“termination problems”` that prohibit making control-flow decisions and evaluating early termination conditions based on encrypted data, as these can leak information. Contrary to generic suites that ignore the fundamental challenges of encrypted computation, our algorithms are tailored to the security primitives of the target encrypted architecture, such as the existence of branching oracles. In our experiments, we compiled our benchmarks for the Cryptoleq architecture and evaluated their performance for a range of security parameters.

TERMinator Suite benchmarks are categorized in three broad classes, depending on the definition of main program loop (Recursive, Exhaustive, Fixed--Iterations).

- __Recursive__: This class comprises divide & conquer algorithms, such as the `Tak function` and the `N-Queens` problem. The termination condition in recursive benchmarks is encrypted, so, to avoid termination problems, a maximum recursion depth is required.
    __1)__ Tak function
    __2)__ N-Queens problem
    __3)__ Set Permutations

- __Exhaustive__: The exhaustive class includes benchmarks that always perform the maximum (worst-case) number of iterations for each input size, to avoid termination problems. Algorithms in this class include `Private Set Intersection`, `Private Insertion Sort` and others, where all inputs are encrypted.
    __4)__ Private Set Intersection
    __5)__ Private Insertion Sort
    __6)__ Primes (Sieve of Eratosthenes)
    __7)__ Matrix Multiplication
    __8)__ Data Deduplication algorithm

    - __Bitwise Operations Sub-Category__: Encrypted computation frameworks (like Cryptoleq) does not support natively bitwise operations. This sub-category of the Exhaustive class, consists of benchmarks that do heavy use of bitwise operators. We have implemented bitwise ```OR, AND, XOR, ROL and ROR``` operations by iterating all bits of both numbers and by comparing the LSBs. ROR and ROL stand for ROtate Right and Left respectively. Rotate operators are widely used in cryptographic block ciphers, like Speck and Simon.
        __9)__ Speck Block Cipher
        __10)__ Simon Block Cipher
        Bitwise AND, OR, XOR, ROR, ROL helper functions

- __Fixed--Iterations__: This class includes benchmarks sensitive to execution time side-channels (i.e., runtime is an affine function of the secret input). To maintain privacy, a fixed number of iterations is provided along with encrypted inputs, and the algorithm computes all possible results before obliviously selecting the correct output.
    __11)__ Factorial
    __12)__ Fibonacci

- __Other Algorithms in the Suite__:
    __1)__ Private Information Retrieval (PIR)
    __2)__ Number Occurrences
        <!-- __3)__ Jenkins (one-at-a-time) hash function -->


#### Installation & How to run a Benchmark
##### Setup Cryptoleq & TERMinator Suite
See instructions [here](https://github.com/momalab/privacy_benchmarks/tree/master/INSTALL.md).

##### How to run a Benchmark
See instructions [here](https://github.com/momalab/privacy_benchmarks/tree/master/HOWTORUN.md).


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
