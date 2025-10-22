// Name: Prajwal Khatiwada
// Compilation command on OMEGA: gcc lab3.c -o lab3
// Run command on Omega for input lab2.a.dat : ./lab3 a.out < lab3.a.dat
// Run command on Omega for input lab2.b.dat : ./lab3 a.out < lab3.b.dat
// Run command on Omega for input lab2.c.dat : ./lab3 a.out < lab3.c.dat

#include <stdio.h>
#include <stdlib.h>
#define MAX 51

int getM(int M[MAX][MAX], int i, int j)
{
    if (i >= j)
    {
        return M[i][j];
    }
    else
    {
        return M[j][i];
    }
}
int find_p(int i, int f[], int s[])
{
    int low = 1;
    int high = i - 1;
    int result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (f[mid] <= s[i])
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
void get_single(int k, int m[], int p[], int v[], int list[], int *count)
{
    *count = 0;
    int temp[MAX];
    int tc = 0;
    int cur = k;
    while (cur > 0)
    {
        if (m[cur] == m[cur - 1])
        {
            cur = cur - 1;
        }
        else
        {
            temp[tc++] = cur;
            cur = p[cur];
        }
    }
    // Reverse to add in ascending order, but not necessary
    for (int ii = tc - 1; ii >= 0; ii--)
    {
        list[(*count)++] = temp[ii];
    }
}
void reconstruct(int i, int j, int M[MAX][MAX], int choice[MAX][MAX], int p[], int v[], int m[], int list1[], int *count1, int list2[], int *count2)
{
    if (i == 0 && j == 0)
    {
        return;
    }
    if (i < j)
    {
        // Swap rooms
        reconstruct(j, i, M, choice, p, v, m, list2, count2, list1, count1);
        return;
    }
    // Now i >= j
    if (j == 0)
    {
        get_single(i, m, p, v, list1, count1);
        return;
    }
    if (i == 0)
    {
        get_single(j, m, p, v, list2, count2);
        return;
    }
    if (i == j)
    {
        reconstruct(i, j - 1, M, choice, p, v, m, list1, count1, list2, count2);
        return;
    }
    // i > j
    int ch = choice[i][j];
    if (ch == 0)
    {
        // Skip
        reconstruct(i - 1, j, M, choice, p, v, m, list1, count1, list2, count2);
    }
    else
    {
        // Use i in the larger room
        reconstruct(p[i], j, M, choice, p, v, m, list1, count1, list2, count2);
        list1[(*count1)++] = i;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int s[MAX], f[MAX], v[MAX], p[MAX], m[MAX];
    int M[MAX][MAX];
    int choice[MAX][MAX];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &s[i], &f[i], &v[i]);
    }
    // Echo input
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d %d\n", s[i], f[i], v[i]);
    }
    // Compute p
    p[0] = 0; // Not used
    for (int i = 1; i <= n; i++)
    {
        p[i] = find_p(i, f, s);
    }
    // Print p[i]
    printf("Rightmost predecessors p[i] (one room):\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    // Compute single room m
    m[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int opt1 = m[i - 1];
        int opt2 = v[i] + m[p[i]];
        m[i] = (opt1 > opt2) ? opt1 : opt2;
    }
    // Print m[i]
    printf("One-room DP m[i]:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", m[i]);
    }
    printf("\n");
    // Initialize M
    for (int i = 0; i <= n; i++)
    {
        for (int jj = 0; jj <= n; jj++)
        {
            M[i][jj] = 0;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        M[i][0] = m[i];
        M[0][i] = m[i];
    }
    // Fill DP
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int val;
            if (j == i)
            {
                val = getM(M, i, j - 1);
            }
            else
            {
                int opt1 = getM(M, i - 1, j);
                int opt2 = v[i] + getM(M, p[i], j);
                val = (opt1 > opt2) ? opt1 : opt2;
                choice[i][j] = (val == opt2) ? 1 : 0;
            }
            M[i][j] = val;
        }
    }
    // Print DP table with labeling
    printf("\nDynamic Programming Table M(i,j):\n");
    printf("    ");
    for (int jj = 0; jj <= n; jj++)
    {
        printf("%4d", jj);
    }
    printf("\n\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%4d", i);
        for (int jj = 0; jj <= n; jj++)
        {
            printf("%4d", getM(M, i, jj));
        }
        printf("\n");
    }
    // Reconstruct
    int room1_list[MAX], room2_list[MAX];
    int count1 = 0, count2 = 0;
    reconstruct(n, n, M, choice, p, v, m, room1_list, &count1, room2_list, &count2);
    // Output
    printf("%d\n", count1);
    for (int i = 0; i < count1; i++)
    {
        int idx = room1_list[i];
        printf("%d %d %d\n", s[idx], f[idx], v[idx]);
    }
    printf("%d\n", count2);
    for (int i = 0; i < count2; i++)
    {
        int idx = room2_list[i];
        printf("%d %d %d\n", s[idx], f[idx], v[idx]);
    }
    printf("%d\n", getM(M, n, n));
    return 0;
}