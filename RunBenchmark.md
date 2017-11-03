# TERMinator Suite
## Benchmarks for Privacy Preserving Architectures

#### How to run a benchmark
Step 1: ensure that all benchmarks are inside the ```cryptoleq/scr/ceal/tests/``` directory. 

Step 2: ```cd``` to the benchmark you want to run (e.g., ```cd ./factorial```) and execute the following command:

```../../_bin_unx/ceal factorial_s.sca```

**Warning:** It is important to run each benchmark within its directory (as in the previous example), and not from the ```tests``` directory, since the ```ceal``` executable includes the ```lib``` folder from the parent directory.

