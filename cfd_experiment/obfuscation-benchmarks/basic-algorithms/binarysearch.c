#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

bool OBF_FUNC(int a[], int n, int m)
{
    int l;
    int u;
    int mid;
    l = 0;
    u = n - 1;
    while (l <= u)
    {
        mid = (l + u) / 2;
        if (m == a[mid])
        {
            return true;
        }
        else if (m < a[mid])
        {
            u = mid - 1;
        }
        else
            l = mid + 1;
    }
    return false;
}

int main(int argc, char* argv[]) {

    return 0;
}
