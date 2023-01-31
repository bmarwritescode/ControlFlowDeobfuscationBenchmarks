#include <stdlib.h>

// next prime
int OBF_FUNC(int n) {
    int i = 2;
    while (i <= n / 2) {
        if (n % i == 0) {
            n++;
            i = 2;
            continue;
        }
        i++;
    }
    return n;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}