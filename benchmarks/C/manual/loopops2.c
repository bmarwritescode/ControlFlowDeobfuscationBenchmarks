#include <stdlib.h>

int OBF_FUNC(int n) {
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        if (sum > 100) {
            break;
        }
        i++;
    }
    return sum;
}


int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
