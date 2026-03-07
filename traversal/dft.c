#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

struct Vertex {
    char label;
    bool visited;
};

int stack[MAX];
int top = -1;

struct Vertex* lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;

// Stack operations
void push(int item){
    stack[++top] = item;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

bool isStackEmpty(){
    return top == -1;
}

// Add vertex
void addVertex(char label){
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

// Display vertex
void displayVertex(int v){
    printf("%c ", lstVertices[v]->label);
}

// Get adjacent unvisited vertex
int getAdjUnvisitedVertex(int v){
    for(int i=0;i<vertexCount;i++){
        if(adjMatrix[v][i]==1 && lstVertices[i]->visited==false){
            return i;
        }
    }
    return -1;
}

// DFS
void depthFirstSearch(){

    lstVertices[0]->visited = true;
    displayVertex(0);

    push(0);

    while(!isStackEmpty()){

        int unvisitedVertex = getAdjUnvisitedVertex(peek());

        if(unvisitedVertex == -1){
            pop();
        }else{
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }
    for(int i=0;i<vertexCount;i++){
        lstVertices[i]->visited = false;
    }
}

int main(){

    int n,i,j;

    printf("Enter number of vertices: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char label;
        printf("Enter label for vertex %d: ",i);
        scanf(" %c",&label);
        addVertex(label);
    }

    printf("\nEnter adjacency matrix:\n");

    for( i=0;i<n;i++){
        for( j=0;j<n;j++){
            scanf("%d",&adjMatrix[i][j]);
        }
    }

    printf("\nDFS Traversal: ");
    depthFirstSearch();

    return 0;
}