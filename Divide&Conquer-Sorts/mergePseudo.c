#include <stdio.h>
void mergePseudo(int a[], int c[], int low, int mid, int high)
{
    int i = low;
    int j = mid;
    int k = low;
    while (i < mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = a[j];
            j++;
            k++;
        }
    }
    while (i < mid)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        j++;
        k++;
    }
}
int main()
{
    int a[] = {9, 9, 8, 18, 18};
    int c[5];

    int low, mid, high;
    low = 0;
    mid = 2;
    high = 4;

    mergePseudo(a, c, low, mid, high);

    for (int i = 0; i <= high; i++)
    {
        a[i] = c[i];
        printf("%d ", a[i]);
    }
    return 0;
}