#include <stdio.h>
void insertionSort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) // starting from second index as we are assuming first index is sorted.
    {
        temp = a[i];
        j = i - 1;

        while (a[j] > temp && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
int main()
{
    int a[] = {7, 12, 3, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}