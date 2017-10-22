### Bitwise Operators
Cryptoleq does not support natively bitwise operations. Thus we have simulated bitwise ```OR, AND, and XOR``` operations by iterating all bits of both numbers and by comparing the LSBs.
We have also added two more complex operators, ```ROR and ROL```, which are ROtate Right and Left respectively.

**Open values:** The word size (beta).

**Encrypted Values:** The input and the output values.

**Result:** These operators protects both the input and the output numbers.

**The source code of this benchmark is available both in `C` as well as `CEAL` (`.sca`) format. In CEAL, `_o.sca` denotes a program without privacy protections, while `_s.sca` denotes a privacy-preserving program. Moreover, `.opn` denotes an unencrypted input file, while `.sec` denotes an encrypted input file.**
