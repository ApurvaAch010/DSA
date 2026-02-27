#include<stdio.h>

const int INF = 999;
const int MAX = 100;

int main()
{
    int n, edges, u, v, w, type;
    int dist[MAX], visited[MAX], parent[MAX], source;
    int graph[MAX][MAX];

    printf("Enter number of vertices:");
    scanf("%d", &n);

    printf("Enter number of edges:");
    scanf("%d", &edges);

    printf("Enter 1 for directed graph and 2 for undirected graph:");
    scanf("%d", &type);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = INF;

    printf("Enter edges in format : u v weight \n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        if (type == 2)
            graph[v][u] = w;
    }

    printf("Enter source vetex:");
    scanf("%d", &source);

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = -1, minDist = INF;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Shortest distance from %d to %d is %d\n", source, i, dist[i]);
        printf(" | Path: ");

        int path[MAX], pathLen = 0;
        int current = i;

        while (current != -1)
        {
            path[pathLen++] = current;
            current = parent[current];
        }

        for (int j = pathLen - 1; j >= 0; j--)
        {
            printf("%d", path[j]);
            if (j > 0)
                printf(" -> ");
        }
        printf("\n");
    }

    return 0;
}