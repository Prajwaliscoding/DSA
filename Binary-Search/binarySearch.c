#include <stdio.h>
int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        if (arr[mid] > target)
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 4;

    printf("The targeted element is in index %d.\n", binarySearch(arr, n, target));
    return 0;
}