#include <stdio.h>
#include <stdbool.h>

bool binarysearch(int a[], int n, int m)
{
    int l, u, mid;
    l = 0, u = n - 1;
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
