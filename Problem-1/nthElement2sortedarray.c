#include <stdio.h>
#include <stdlib.h>
enum
{
    NEG_SENTINEL = -99999999,
    POS_SENTINEL = 99999999
};

void binarySearch(int *ptr, int *qtr, int *rtr, int m, int n, int p)
{
    printf("\n");
    for (int x = 0; x < p; x++)
    {
        int r = rtr[x];

        if (r < 1 || r > m + n)
        {
            printf("Rank %d is out of range.\n", r);
            continue;
        }

        int low, high;
        low = (n >= r) ? 0 : (r - n);
        high = (m >= r) ? r : m;

        int i, j;
        while (low <= high)
        {
            i = (low + high) / 2;
            j = r - i;

            if (ptr[i] <= qtr[j] && ptr[i + 1] > qtr[j]) // cant put ptr[i+1] >= qtr[j] because in this case we should take it from first array
            {
                printf("low %d high %d i %d j %d a[%d]=%d b[%d]=%d a[%d]=%d\n",
                       low, high, i, j, i, ptr[i], j, qtr[j], i + 1, ptr[i + 1]);
                printf("b[%d] = %d has rank %d.\n\n", j, qtr[j], r);
                break;
            }
            if (qtr[j] < ptr[i] && qtr[j + 1] >= ptr[i])
            {
                printf("low %d high %d i %d j %d b[%d]=%d a[%d]=%d b[%d]=%d\n",
                       low, high, i, j, j, qtr[j], i, ptr[i], j + 1, qtr[j + 1]);
                printf("a[%d] = %d has rank %d.\n\n", i, ptr[i], r);
                break;
            }

            if (ptr[i] > qtr[j + 1])
            {
                printf("low %d high %d i %d j %d b[%d]=%d a[%d]=%d b[%d]=%d\n",
                       low, high, i, j, j, qtr[j], i, ptr[i], j + 1, qtr[j + 1]);
                high = i - 1;
            }
            else if (qtr[j] >= ptr[i + 1])
            {
                printf("low %d high %d i %d j %d a[%d]=%d b[%d]=%d a[%d]=%d\n",
                       low, high, i, j, i, ptr[i], j, qtr[j], i + 1, ptr[i + 1]);
                low = i + 1;
            }
        }
    }
}
int main()
{
    int m, n, p;
    printf("Enter m, n and p:\n");
    scanf("%d%d%d", &m, &n, &p);

    int *ptr, *qtr, *rtr;
    printf("Enter those things now: \n");

    ptr = (int *)malloc((m + 2) * sizeof(int));
    for (int e = 1; e <= m; e++)
    {
        scanf("%d", &ptr[e]);
    }

    qtr = (int *)malloc((n + 2) * sizeof(int));
    for (int f = 1; f <= n; f++)
    {
        scanf("%d", &qtr[f]);
    }

    rtr = (int *)malloc(p * sizeof(int));
    for (int g = 0; g < p; g++)
    {
        scanf("%d", &rtr[g]);
    }

    ptr[0] = NEG_SENTINEL;
    ptr[m + 1] = POS_SENTINEL;
    qtr[0] = NEG_SENTINEL;
    qtr[n + 1] = POS_SENTINEL;

    binarySearch(ptr, qtr, rtr, m, n, p);

    free(ptr);
    free(qtr);
    free(rtr);
    return 0;
}