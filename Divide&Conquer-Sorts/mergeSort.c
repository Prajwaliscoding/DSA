// included mid in first half
#include <stdio.h>
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int c[5];
    while (i <= mid && j <= high)
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
    while (i <= mid)
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
    for (int i = low; i <= high; i++)
    {
        a[i] = c[i];
    }
}
void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main()
{
    int a[] = {9, 8, 19, 12, 7};

    int low = 0;
    int n = sizeof(a) / sizeof(a[0]);
    int high = n - 1;

    mergeSort(a, low, high);

    printArray(a, n);
}