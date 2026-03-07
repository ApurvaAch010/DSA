#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], parent[MAX];
int n;

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void inputGraph()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
}

void kruskal()
{
    int i, j, a, b, u, v;
    int ne = 1;
    int min, mincost = 0;

    printf("Edges of Minimum Cost Spanning Tree:\n");

    while(ne < n)
    {
        for(i = 1, min = INF; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u, v))
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum cost = %d\n", mincost);
}

int main()
{
    inputGraph();
    kruskal();
    return 0;
}