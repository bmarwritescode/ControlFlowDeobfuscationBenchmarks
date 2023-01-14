Source: https://github.com/tum-i4/obfuscation-benchmarks

# Obfuscation Benchmarks

- The `simple-hash-functions` directory has a collection of basic hash functions
that accept a byte array as input and produce an integer output.
In order to deobfuscate similar hash functions, it is necessary to expand our tool to
process an arbitrary number of parameters.

The control flow structure of these hash functions is relatively straightforward.
As such, it may be beneficial to implement various obfuscation techniques to
increase the complexity of the structure.

```c
unsigned int BPHash(char* str, unsigned int len)
{
   unsigned int hash = 0;
   unsigned int i    = 0;
   for(i = 0; i < len; str++, i++)
   {
      hash = hash << 7 ^ (*str);
   }

   return hash;
}
```


- `basic-algorithms` contains typical algorithms taught in Bachelor level computer science and programming courses, e.g. factorial, sorting algorithms, searching algorithms, greatest common divisor, least common multiple, etc.

- `small-programs` contains a set of 48 programs with few lines of code constructed by varying the following code characteristics:
    - Range of symbolic inputs
    - Number of symbolic inputs
    - Depth of nested control flow
    - Number of IF-statements
    - Number of input dependent IF-statements
    - Type of IF-condition
    - Number of loops
    - Number of input length dependent loops (e.g. if the input is 10 characters long, then the loop has 10 iterations)
    - Number of input value dependent loops (e.g. if the input is an integer equal to 100, then the loop has 100 iterations)