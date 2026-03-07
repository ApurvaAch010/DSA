#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

struct queue{
    int items[SIZE];
    int front;
    int rear;
};

struct node{
    int vertex;
    struct node* next;
};

struct Graph{
    int numVertices;
    struct node** adjLists;
    int* visited;
};

struct queue* createQueue()
{
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct queue* q)
{
    if(q->rear == -1)
        return 1;
    return 0;
}

void enqueue(struct queue* q,int value)
{
    if(q->rear == SIZE-1)
        printf("Queue Full\n");
    else{
        if(q->front == -1)
            q->front = 0;

        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q)
{
    int item;

    if(isEmpty(q)){
        printf("Queue Empty\n");
        return -1;
    }

    item = q->items[q->front];
    q->front++;

    if(q->front > q->rear)
        q->front = q->rear = -1;

    return item;
}

struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices*sizeof(struct node*));
    graph->visited = malloc(vertices*sizeof(int));

    for(int i=0;i<vertices;i++){
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph,int src,int dest)
{
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void bfs(struct Graph* graph,int startVertex)
{
    struct queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q,startVertex);

    while(!isEmpty(q)){
        int currentVertex = dequeue(q);
        printf("%d ",currentVertex);

        struct node* temp = graph->adjLists[currentVertex];

        while(temp){
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(q,adjVertex);
            }

            temp = temp->next;
        }
    }
}

int main()
{
    int vertices,edges,src,dest,start;

    printf("Enter number of vertices: ");
    scanf("%d",&vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d",&edges);

    printf("Enter edges (src dest):\n");

    for(int i=0;i<edges;i++){
        scanf("%d %d",&src,&dest);
        addEdge(graph,src,dest);
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d",&start);

    printf("BFS Traversal: ");
    bfs(graph,start);

    return 0;
}