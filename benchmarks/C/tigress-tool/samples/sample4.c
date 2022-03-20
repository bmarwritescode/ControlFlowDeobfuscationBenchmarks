/*
** adler32
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

const uint32_t MOD_ADLER = 65521;

uint32_t SECRET(unsigned long input) {
  unsigned char *data = (unsigned char*)&input;
  size_t len = sizeof(input);
  uint32_t a = 1, b = 0;
  uint32_t c = (a >> 2) * b / 7;
  size_t index;

  c += 2;
  for (index = 0; index < len; ++index) {
    if (index == len - 1 && data[index] % 2) c += input;
  }

  /* Process each byte of the data in order */
  for (index = 0; index < len; ++index) {
    a = (a + data[index]) % MOD_ADLER;
    b = (b + a) % MOD_ADLER;
    c = (a + data[index] + b) % MOD_ADLER;
  }

  b += (c ^ c) * 70;
  return (b << 16) | a;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Call this program with 1 arguments\n");
        return 1;
    }

    unsigned long input = strtoul(argv[1], 0, 10);
    uint32_t output = SECRET(input);

    printf("%u\n", output);

    return 0;
}
