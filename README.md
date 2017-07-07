## Benchmarks for Privacy Preserving Architectures

### Configuration
First clone and set up the cryptoleq [repository](https://github.com/momalab/cryptoleq), as shown [here](https://github.com/momalab/cryptoleq/blob/master/doc/build_ceal.pdf):

```git clone https://github.com/momalab/cryptoleq.git```


Second clone the benchmarks repository:

```git clone https://github.com/momalab/privacy_benchmarks.git```


Finally, copy all the benchmark files inside the cryptoleq directory:

```cp -rf ./privacy-benchmarks/* ./cryptoleq/scr/ceal/tests/```



### Running a benchmark
Now all the benchmarks are inside the ```cryptoleq/scr/ceal/tests/``` directory. ```cd``` to the benchmark you want to run (e.g. ```cd ./factorial```) and execute the following command ```../../_bin_unx/ceal factorial_s.sca```.

**Warning:** It is important that you run each benchmark through its directory (as the example above), and not from the tests directory because the ```ceal``` executable searches for the ```lib``` folder in the parent directory.


### Benchmarks

- __[N-Queens](https://github.com/momalab/privacy_benchmarks/tree/master/nqueens)__ [wiki](https://en.wikipedia.org/wiki/Eight_queens_puzzle)
    * The 8-queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal. The N-Queens problem is the problem of placing N queens on an NxN chessboard.
    * __Threat Model:__  In this benchmark, we solely protect the output data (e.g. the queens positions), as the only input data is the number of the queens, which we define as open--value.


- __[Tak function](https://github.com/momalab/privacy_benchmarks/tree/master/tak_function)__ [wiki](https://en.wikipedia.org/wiki/Tak_(function))
    * In computer science, the Tak function is a recursive function, named after Ikuo Takeuchi. Tak function is a popular recursion performance test.
    * __Threat Model:__ Every variable is encrypted.


- __[Insertion-sort](https://github.com/momalab/privacy_benchmarks/tree/master/insertionSort)__ [wiki](https://en.wikipedia.org/wiki/Insertion_sort)
    * Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. 
    * Performance:
        - Worst-case: О(n^2)
        - Average: О(n^2)
        - Best-case: O(n)
    * __Threat Model:__ In this benchmark, we do not care to protect the size of the array, only the contents of both the input/unsorted and output/sorted arrays.


- __[Set Intersection](https://github.com/momalab/privacy_benchmarks/tree/master/PSI)__ [PSI](https://www.cs.virginia.edu/~evans/pubs/ndss2012/psi.pdf)
    * Protocols for private set intersection PSI allow two parties holding sets S and S' to compute the intersection I = S ∩ S' without revealing to the other party any additional information about their respective sets (except their sizes).
    * __Threat Model:__ In this benchmark, we care to protect the contents of the sets. We do not care to protect the size (N) of the biggest set which is given as open value; the smaller array is extended also in size N and filled up with a fixed value.


- __[Fibonacci](https://github.com/momalab/privacy_benchmarks/tree/master/fibonacci)__ [wiki](https://en.wikipedia.org/wiki/Fibonacci_number)
    * The Fibonacci numbers are the numbers in a sequence that is characterized by the fact that every number after the first two is the sum of the two preceding ones.
    * __Threat Model:__ The input number is given encrypted, while we have modified the algorithm in a way to protect the input from information leaked from the computation time.
    * The only arrangement is that the program can compute up to a maximum/fixed number (N). When the user asks for the fib(X), 0 <= x <= N, the program computes every fib in range [0, N] and prints the fib(X). This arrangement was made in order to protect the data from side channel attacks, like leaking information about X from the computation time.


- __[Factorial](https://github.com/momalab/privacy_benchmarks/tree/master/factorial)__ [wiki](https://en.wikipedia.org/wiki/Factorial)
    * The factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n.
    * __Threat Model:__ Same as Fibonacci.
    

- __[Matrix Multiplication](https://github.com/momalab/privacy_benchmarks/tree/master/matrixMultiplication)__ [wiki](https://en.wikipedia.org/wiki/Matrix_multiplication)
    * Matrix multiplication is a binary operation that produces a matrix from two matrices. If A is an ```n × m``` matrix and B is an ```m × p``` matrix, their matrix product AB is an ```n × p``` matrix, in which the m entries across a row of A are multiplied with the m entries down a columns of B and summed to produce an entry of AB.
    * __Threat Model:__ In this benchmark, we are protecting the contents of the matrices, we do not care to protect the dimensions (```n m m p```) which are given as open values.
    * The matrix product is a ```n × p``` matrix with encrypted values.


- __[Permutations](https://github.com/momalab/privacy_benchmarks/tree/master/permutations)__ [wiki](https://en.wikipedia.org/wiki/Permutation)
    * The notion of permutation relates to the act of arranging all the members of a set into some sequence or order, or if the set is already ordered, rearranging its elements, a process called permuting. This benchmark, computes all permutations of a given array/set.
    * __Threat Model:__ In this benchmark, we do not care to protect the size of the array. We are protecting the contents of the input, as well as all the output/permuted arrays.


- __[Sieve of Eratosthenes](https://github.com/momalab/privacy_benchmarks/tree/master/sieveOfEratosthenes)__ [wiki](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
    * In mathematics, the sieve of Eratosthenes, is a simple, ancient algorithm for finding all prime numbers up to any given limit. It does so by iteratively marking as composite (i.e. not prime) the multiples of each prime, starting with the multiples of 2. In this benchmark, we print all prime numbers up to a fixed/maximum number using the sieve of Eratosthenes method.
    * __Threat Model:__ In this benchmark, the only open value will be the maximum number to compute if it is prime. In order to protect both the primes themselves and the number of primes found from 2 to Num, if a number is prime we print the encryption of that prime, else we print the encryption of zero.


- __[Prime Numbers](https://github.com/momalab/privacy_benchmarks/tree/master/prime_numbers)__ [wiki](https://en.wikipedia.org/wiki/Prime_number)
    * A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself. In this benchmark, we find and print all prime numbers from 2 to a fixed/maximum number N. In this benchmark, we use the [Sieve of Eratosthenes](https://github.com/momalab/privacy_benchmarks/tree/master/sieveOfEratosthenes) in rounds in order to calculate prime numbers without stopping.
    * __Threat Model:__  Same as in the Sieve of Eratosthenes benchmark. 


- __[Number Occurrences](https://github.com/momalab/privacy_benchmarks/tree/master/numOccurrences)__
    * Given an array of integers count the occurrences of a specific number.
    * __Threat Model:__ The input number as well as the array of integers are given encrypted. No information leaked.


*Source: Wikipedia*


### Security Parameter (N)
The security parameter (\texttt{N}) is a prime number that ranges from 64 to 1024 bits; the latter is the minimum standard not yet broken size. As the bits of the security parameter increase, the function \texttt{G} becomes slower.

To change the security parameter of a benchmark you should modify the ```.pragma PQ``` line which is at the start of the each benchmark ```.sca``` file. Below are some examples that range from 16 to 1024 bits.

```
.pragma PQ=239.251
.pragma PQ=63199.64567
.pragma PQ=4281167959.4271299633
.pragma PQ=18299379327617480707.18345258783657292909
.pragma PQ=338871469111127928412308213206819656391.338531414912581056934822037249894061881
.pragma PQ=115689526107095890311249333520175779978137070980169508677335528535095435701957.115509443392406915656501893779637949187966713758992043305916442498716409678501
.pragma PQ=13392849694255970315601419090152597688339809774933571293865724091737666496951381207429127235940384883608845778583380210687006370486238723021460371010217257.13403952390292880134486926689236901739298695038033079040680862117777593853851234125818128702776151240584166261477766002390185782669746209391687589482784501
```
