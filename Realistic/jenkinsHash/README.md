### Jenkins one-at-a-time Hash Function
The Jenkins hash functions are a collection of (non-cryptographic) hash functions for multi-byte keys designed by Bob Jenkins. The first one was formally published in 1997.

```
uint32_t jenkins_one_at_a_time_hash(const uint8_t* key, size_t length) {
    size_t i = 0;
    uint32_t hash = 0;
    while (i != length) {
        hash += key[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
  return hash;
}
```

**Open values:** The size (length) of the input array. 

**Encrypted Values:** All array elements.

Jenkins hash function uses a lot of bitwise operations, which are not natively supported in encrypted computation architectures, like Cryptoleq. There is no actual access to the bits, since all data are encrypted. Thus, we use the [simulated bitwise operations](https://github.com/momalab/privacy_benchmarks/tree/master/Realistic/bitwiseOperators) that TERMinator Suite provides.

**The source code of this benchmark is available both in `C` as well as `CEAL` (`.sca`) format. In CEAL, `_o.sca` denotes a program without privacy protections, while `_s.sca` denotes a privacy-preserving program. Moreover, `.opn` denotes an unencrypted input file, while `.sec` denotes an encrypted input file.**
