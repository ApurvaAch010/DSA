#include<stdio.h>

#define INF 9999999
#define MAX 20

int G[MAX][MAX];
int V;

void inputGraph()
{
    printf("Enter number of vertices: ");
    scanf("%d",&V);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
}

void prims()
{
    int no_edge=0;
    int selected[MAX];
    int i,j,min;

    for(i=0;i<MAX;i++)
        selected[i]=0;

    selected[0]=1;

    int x,y;

    printf("Edge : Weight\n");

    while(no_edge < V-1)
    {
        min=INF;
        x=0;
        y=0;

        for(i=0;i<V;i++)
        {
            if(selected[i])
            {
                for(j=0;j<V;j++)
                {
                    if(!selected[j] && G[i][j])
                    {
                        if(min > G[i][j])
                        {
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n",x,y,G[x][y]);
        selected[y]=1;
        no_edge++;
    }
}

int main()
{
    inputGraph();
    prims();
    return 0;
}