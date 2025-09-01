#include <stdio.h>
void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void selectionSort(int a[], int ell, int r)
{
    int i, j;
    for (i = ell; i < r; i++)
    {
        int min_index = i;
        for (j = i + 1; j <= r; j++)
        {
            if (a[min_index] > a[j])
            {
                min_index = j;
            }
        }
        swap(&a[i], &a[min_index]);
    }
}
int main()
{
    int a[] = {5, 3, 0, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int ell = 0, r = n - 1;
    selectionSort(a, ell, r);

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    return 0;
}