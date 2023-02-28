#include <stdlib.h>

int OBF_FUNC(int n) {
   int a = 1;
   int b = 1;
   int i;
   i = 3;
   for (; i <= n;) {
      int c = a + b;
      a = b;
      b = c;
      i++;
   };
   return b;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}

