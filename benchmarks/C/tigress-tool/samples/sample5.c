/*
** Jenkins's one-at-a-time
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t SECRET(unsigned long input) {
  unsigned char *key = (unsigned char*)&input;
  size_t length = sizeof(input);
  size_t i = 0;
  i += length * ((size_t) key);
  i ^= length;
  length += i ^ i;
 
  uint32_t hash = 0;
  hash = length + i;
  i = hash & ~hash;
  i -= i;
  hash = (i = 0);

  uint32_t foo_1 = 0;

  while (i != length && ((foo_1 % 2 == 0) || (foo_1 & 1))) {
    hash += key[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
    foo_1 ^= hash >> 8;
  }

  i += (hash >> 3) + foo_1;
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash;
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
