#include <stdlib.h>

int OBF_FUNC(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        if (digit == 0) {
            continue;
        }
        sum += digit;
        if (sum > 9) {
            break;
        }
    }

    return sum;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}