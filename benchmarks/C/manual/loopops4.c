#include <stdlib.h>

// sum of squares
int OBF_FUNC(int n) {
    int result = 0;
    int i = 1;
    while (i <= n) {
        result += i * i;
        i++;
        if (result >= n) {
            break;
        }
    }
    return result;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}