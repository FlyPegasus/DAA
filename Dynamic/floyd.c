// Multi Source shortest path algorithm using Dynamic Programming
#include <stdio.h>
#define INF 9999
int n = 5;
// Cost matrix premade
int cost[4][4] = {{0, 2, INF, INF}, {1, 0, 3, INF}, {INF, INF, 0, INF}, {3, 5, 4, 0}}; // Storage matrix for computing all pair shortest path
/*
Cost matrix needs initialisation of 0 cost for each same vertex
*/
void floyd()
{
    for (int i = 0; i < n; i++) // through i
    {
        for (int j = 0; j < n; j++) // row j
        {
            for (int k = 0; k < n; k++) // col k
            {
                if (cost[j][i] + cost[i][k] < cost[j][k])
                {
                    cost[j][k] = cost[j][i] + cost[i][k];
                }
            }
        }
    }
}
int main(void)
{
    printf("All Shortest Path:\n");
    floyd();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}