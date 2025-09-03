// Program to get a symmetric difference out of two arrays in ascending order in linear time.
#include <stdio.h>
void symmetricDifference(int a[], int b[], int c[], int m, int n)
{
    int i, j, p;
    i = j = p = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[p] = a[i];
            i++;
            p++;
        }
        else if (b[j] < a[i])
        {
            c[p] = b[j];
            j++;
            p++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < m)
    {
        c[p] = a[i];
        i++;
        p++;
    }
    while (j < n)
    {
        c[p] = b[j];
        j++;
        p++;
    }
    for (int k = 0; k < p; k++)
    {
        printf("%d ", c[k]);
    }
}
int main()
{
    int a[] = {3, 6, 8, 9, 11};
    int b[] = {1, 4, 6, 7, 9};

    int m, n;

    m = sizeof(a) / sizeof(a[0]);
    n = sizeof(b) / sizeof(b[0]);

    int c[m + n]; // this can blow the stack for very large m and n. Use heap.

    symmetricDifference(a, b, c, m, n);
}