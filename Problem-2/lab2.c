// Name: Prajwal Khatiwada
// ID: 1002239223

// Compilation command on Omega: gcc -o t2 lab2.c
// Run command on Omega for input lab2.a.dat : ./t2 a.out < lab2.a.dat
// Run command on Omega for input lab2.b.dat : ./t2 a.out < lab2.b.dat
// Run command on Omega for input lab2.c.dat : ./t2 a.out < lab2.c.dat

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_subsequence_with_repeats(const int *A, int nA, const int *X, int nX, int rep)
{
    if (rep == 0 || nX == 0)
        return true;
    if ((long long)rep * (long long)nX > (long long)nA)
        return false;
    int iA = 0;
    for (int k = 0; k < nX; ++k)
    {
        int target = X[k], need = rep;
        while (iA < nA && need > 0)
        {
            if (A[iA] == target)
                --need;
            ++iA;
        }
        if (need > 0)
            return false;
    }
    return true;
}

int main(void)
{
    int nA, nX;
    if (scanf("%d %d", &nA, &nX) != 2)
        return 0;

    int *A = (int *)malloc((size_t)nA * sizeof(int));
    if (!A)
        return 0;
    for (int i = 0; i < nA; ++i)
        if (scanf("%d", &A[i]) != 1)
        {
            free(A);
            return 0;
        }

    int tmp;
    if (scanf("%d", &tmp) != 1)
    {
        free(A);
        return 0;
    }

    int *X = (int *)malloc((size_t)nX * sizeof(int));
    if (!X)
    {
        free(A);
        return 0;
    }
    for (int i = 0; i < nX; ++i)
        if (scanf("%d", &X[i]) != 1)
        {
            free(A);
            free(X);
            return 0;
        }

    if (scanf("%d", &tmp) != 1)
    {
        free(A);
        free(X);
        return 0;
    }

    int low = 0;
    int high = (nX == 0) ? nA : (nA / (nX == 0 ? 1 : nX));
    int best = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool ok = is_subsequence_with_repeats(A, nA, X, nX, mid);
        printf("low %d mid %d high %d  %s\n", low, mid, high, ok ? "passed" : "failed");
        if (ok)
        {
            best = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Maximum repeats is %d\n", best);

    free(A);
    free(X);
    return 0;
}
