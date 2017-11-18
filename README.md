# TERMinator Suite
## Benchmarks for Privacy Preserving Architectures

Security and privacy are fundamental objectives characterizing contemporary cloud computing. Despite the wide adoption of encryption for protecting data in transit and at rest, data in use remains unencrypted inside cloud processors and memories, as computation is not applicable on encrypted values. This limitation introduces security risks, as unencrypted values can be leaked through side-channels or hardware Trojans. To address this problem, encrypted architectures have recently been proposed, which leverage homomorphic encryption to natively process encrypted data using datapaths of thousands of bits. In this case, additional security protections are traded for higher performance penalties, which drives the need for more efficient architectures. In this work, we develop benchmarks specifically tailored to encrypted computers, to enable comparisons across different architectures. Our benchmark suite, dubbed TERMinator, is unique as it avoids `“termination problems”` that prohibit making control-flow decisions and evaluating early termination conditions based on encrypted data, as these can leak information. Contrary to generic suites that ignore the fundamental challenges of encrypted computation, our algorithms are tailored to the security primitives of the target encrypted architecture, such as the existence of branching oracles. In our experiments, we compiled our benchmarks for the Cryptoleq architecture and evaluated their performance for a range of security parameters.


### TERMinator Suite Benchmark Categories
* __Encoder Benchmarks__: This class comprises three real-life cryptographic and hash applications (namely `Speck`, `Simon` and `Jenkins`), which are demanding in terms of bitwise operations and branch decisions on encrypted values, and allow assessing the BRO of the target abstract machine.

* __Synthetic__: In this class we have the `NQueens` and `Tak` algorithms, which evaluate the universality of the underlying abstract machine using recursion, in addition to making branch decisions on encrypted control values (a critical functionality for encrypted computation).

* __Kernels__: In this class we have the `Insertion Sort`, `Set Intersection`, `Deduplication (Union)`, `Matrix Multiplication`, `Primes (Sieve of Eratosthenes)`, and `Permutations`, which evaluate essential loops that combine memory swaps, branching oracle calls and arithmetic operations. These kernels also have significance in privacy-sensitive real-life applications: for example, set intersection is used to evaluate collision courses of military satellites without revealing actual paths, while permutations is an important part of DNA sequencing.

* __Microbenchmarks__: In this class we have the `Factorial`, `Fibonacci` and `Private Information Retrieval` algorithms, which evaluate a single critical homomorphic operation of addition and multiplication in the underlying abstract machine. 



### List of TERMinator Suite Benchmarks

* __All benchmarks are available as `C/C++` sources (`.c` files), as well as `CEAL` sources (`.sca` files). `CEAL` provides native support for a branching oracle (function G).__

    #### Synthetic Category
1. __[N-Queens](https://github.com/momalab/TERMinatorSuite/blob/master/Synthetic/nqueens)__ [(link)](http://www.kotesovec.cz/rivin_1994.pdf)

1. __[Tak function](https://github.com/momalab/TERMinatorSuite/blob/master/Synthetic/tak_function)__ [(link)](http://www.users.miamioh.edu/ishiut/papers/tarai_ipl.pdf)

    #### Encoder Benchmarks Category
1. __[Speck (cipher)](https://github.com/momalab/TERMinatorSuite/blob/master/EncoderBenchmarks/SpeckCipher)__ [(link)](https://eprint.iacr.org/2013/404.pdf)

1. __[Simon (cipher)](https://github.com/momalab/TERMinatorSuite/blob/master/EncoderBenchmarks/SimonCipher)__ [(link)](https://eprint.iacr.org/2013/404.pdf)

1. __[Jenkins one-at-a-time Hash Function](https://github.com/momalab/TERMinatorSuite/blob/master/EncoderBenchmarks/jenkinsHash)__ [(link)](http://www.burtleburtle.net/bob/hash/doobs.html)

    #### Kernels Category
1. __[Insertion-sort](https://github.com/momalab/TERMinatorSuite/blob/master/Kernels/insertionSort)__ [(link)](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.45.8017&rep=rep1&type=pdf)

1. __[Private Set Intersection](https://github.com/momalab/privacy_benchmarks/tree/maste/Kernels/PSI)__ [(link)](https://www.cs.virginia.edu/~evans/pubs/ndss2012/psi.pdf)

1. __[Data Deduplication Algorithm](https://github.com/momalab/TERMinatorSuite/blob/master/Kernels/deduplication)__ [(link)](https://dl.acm.org/citation.cfm?id=1456471)

1. __[Permutations](https://github.com/momalab/TERMinatorSuite/blob/master/Kernels/permutations)__ [(link)](http://mathworld.wolfram.com/Permutation.html)

1. __[Sieve of Eratosthenes](https://github.com/momalab/TERMinatorSuite/blob/master/Kernels/sieveOfEratosthenes)__ [(link)](http://mathworld.wolfram.com/SieveofEratosthenes.html)

1. __[Matrix Multiplication](https://github.com/momalab/TERMinatorSuite/blob/master/Kernels/matrixMultiplication)__ [(link)](http://mathworld.wolfram.com/MatrixMultiplication.html)

    #### Microbenchmarks Category
1. __[Private Information Retrieval](https://github.com/momalab/TERMinatorSuite/blob/master/Microbenchmarks/PIR)__ [(link)](https://crysp.uwaterloo.ca/courses/pet/F09/cache/www.dbis.informatik.hu-berlin.de/fileadmin/research/papers/conferences/2001-gi_ocg-asonov.pdf) 

1. __[Factorial](https://github.com/momalab/TERMinatorSuite/blob/master/Microbenchmarks/factorial)__ [(link)](http://mathworld.wolfram.com/Factorial.html)

1. __[Fibonacci](https://github.com/momalab/TERMinatorSuite/blob/master/Microbenchmarks/fibonacci)__ [(link)](http://mathworld.wolfram.com/FibonacciNumber.html)

    #### Other Algorithms
1. __[Number Occurrences](https://github.com/momalab/TERMinatorSuite/blob/master/OtherAlgorithms/numOccurrences)__



### Installation steps & How to run a benchmark
##### Setup Cryptoleq & TERMinator Suite        
To set up Cryptoleq and TERMinator Suite follow the steps [here](https://github.com/momalab/TERMinatorSuite/blob/master/Install.md).

##### How to run a Benchmark
An example of how to run a benchmark is shown [here](https://github.com/momalab/TERMinatorSuite/blob/master/RunBenchmark.md).


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
