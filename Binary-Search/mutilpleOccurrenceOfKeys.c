#include <stdio.h>

int a[20] = {0, 1, 1, 1, 2, 4, 4, 6, 6, 6, 10, 12, 12, 12, 12, 15, 15, 17, 17, 18};

int binSearchFirst(int *a, int n, int key)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int binSearchLast(int *a, int n, int key)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] <= key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}
int main()
{
    int i, first, last, key;

    printf("-- table --\n");
    for (i = 0; i < 20; i++)
        printf("%3d %3d\n", i, a[i]);
    printf("key  first  last  count\n");
    for (i = (-1); i < 21; i++)
    {
        first = binSearchFirst(a, 20, i);
        last = binSearchLast(a, 20, i);
        printf("%3d   %3d   %3d   %3d\n", i, first, last, last - first + 1);
    }
}