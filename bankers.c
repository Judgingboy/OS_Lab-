#include <stdio.h>
int main()
{
    int n, m;
    int
        alloc[10][10],
        max[10][10], need[10][10], avail[10];
    int f[10], safeseq[10], flag, ind = 0, i, j, k, y;
    printf("\nEnter the number of process :");
    scanf("%d", &n);
    printf("\nEnter the number of resources :\n");
    scanf("%d", &m);
    printf("\n Enter the allocation matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("\n Enter the data for P%d: ", i);
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\n Enter the max matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("\nEnter the data for P%d : ", i);
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter the available resources : \n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    for (i = 0; i < n; i++)
    {
        f[i] = 0;
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (f[j] == 0)
            {
                flag = 0;
                for (k = 0; k < m; k++)
                {
                    if (need[j][k] > avail[k])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safeseq[ind++] = j;
                    for (y = 0; y < m; y++)
                    {
                        avail[y] += alloc[j][y];
                    }
                    f[j] = 1;
                }
            }
        }
    }
    printf("\nThe available resources is : \n");
    for (i = 0; i < m; i++)
        printf("%d ", avail[i]);
    printf("\nThe safe sequence is :\n");
    for (i = 0; i < n - 1; i++)
    {
        printf("P[%d] ,", safeseq[i]);
    }
    printf("P[%d]\n", safeseq[n - 1]);
}
