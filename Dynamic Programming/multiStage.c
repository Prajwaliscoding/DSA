// finding the shortest path or minimum cost way to do a job.
#include <stdio.h>
int main()
{
    // Both rows and columns are vertices and when the values are cost.

    /////////////// 0, 1, 2, 3, 4, 5, 6, 7, 8
    int C[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},  // 0
                   {0, 0, 2, 1, 3, 0, 0, 0, 0},  // 1
                   {0, 0, 0, 0, 0, 2, 3, 0, 0},  // 2
                   {0, 0, 0, 0, 0, 6, 7, 0, 0},  // 3
                   {0, 0, 0, 0, 0, 6, 8, 9, 0},  // 4
                   {0, 0, 0, 0, 0, 0, 0, 0, 6},  // 5
                   {0, 0, 0, 0, 0, 0, 0, 0, 4},  // 6
                   {0, 0, 0, 0, 0, 0, 0, 0, 5},  // 7
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 8

    int stage = 4;
    int minDistance[9];
    int path[5];  // same number as stages first index 0 ma j vayeni bal xaina
    int size = 8; // number of vertices
    int cost[9];
    cost[8] = 0;
    int sum = 0;
    for (int i = size - 1; i >= 1; i--)
    {
        int min = 10000;
        for (int k = i + 1; k <= size; k++)
            if (C[i][k] != 0 && C[i][k] + cost[k] < min) // Cost of vertex i  = C[i][k]+cost(k)
            {
                min = C[i][k] + cost[k];
                minDistance[i] = k;
            }
        cost[i] = min;
        sum = sum + cost[i];
    }

    path[1] = 1;
    path[stage] = size;

    for (int i = 2; i < stage; i++)
    {
        path[i] = minDistance[path[i - 1]];
    }
    printf("The optimal solution is %d.\n", sum);
    printf("The path is: ");
    for (int i = 1; i <= stage; i++)
    {
        printf("%d ", path[i]);
    }
}