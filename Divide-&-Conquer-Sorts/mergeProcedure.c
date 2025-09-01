#include <stdio.h>
void mergeProcedure(int a[], int b[], int c[], int m, int n)
{
    int i, j, k;
    i = j = k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }
}
int main()
{
    int a[] = {7, 9, 18, 19, 22};
    int b[] = {1, 6, 9, 11};
    int c[] = {};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    mergeProcedure(a, b, c, m, n);

    for (int i = 0; i < (m + n); i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}