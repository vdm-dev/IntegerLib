# IntegerLib
The IntegerLib was developed by the [CERT/CC](https://github.com/CERTCC) and is freely available.

The purpose of this library is to provide a collection of utility functions that can assist software developers
in writing C programs that are free from common integer problems such as integer overflow, integer
truncation, and sign errors that are a common source of software vulnerabilities.

Functions have been provided for all integer operations subject to overflow such as addition, subtraction,
multiplication, division, unary negation, etc.) for `int`, `long`, `long long`, and `size_t` integers. The
following example illustrates how the library can be used to add two `signed long` integer values:
```
long retsl, xsl, ysl;
xsl = LONG_MAX;
ysl = 0;
retsl = addsl(xsl, ysl);
```
For short integer types (`char` and `short`) it is necessary to truncate the result of the addition using one of
the safe conversion functions provided, for example:
```
char retsc, xsc, ysc;
xsc = SCHAR_MAX;
ysc = 0;
retsc = si2sc(addsi(xsc, ysc));
```
For error handling, the secure integer library uses the mechanism for runtime-constraint handling defined
by ISO/IEC TR 24731.

The implementation uses the high performance algorithms defined by Henry S. Warren in the book
"Hacker's Delight".
