// Guessing the secret number between 1 and 1000
int isCorrect(int num)
{
    if (num == 27)
    {
        return 0;
    }
    else if (num < 27)
    {
        return -1;
    }
    else if (num > 27)
    {
        return 1;
    }
    return -1;
}

int binarySearch(int left, int right)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (isCorrect(mid) == 0)
        {
            return mid;
        }
        if (isCorrect(mid) < 0)
        {
            left = mid + 1;
        }
        else if (isCorrect(mid) > 0)
        {
            right = mid - 1;
        }
    }
    return -1;
}
#include <stdio.h>
int main()
{
    int left = 0;
    int right = 1000;

    printf("The number is %d\n", binarySearch(left, right));
}