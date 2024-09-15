#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct graph{
    int numOfVertices;
    struct node **adjLists;
} graph;

node *makeNode(int value){
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

graph *initializeGraph(int V){
    graph *Graph = (graph*)malloc(sizeof(graph));
    Graph->numOfVertices = V;
    Graph->adjLists = (node**)malloc(V * sizeof(node));
    for(int i = 0; i < V; i++){
        Graph->adjLists[i] = NULL;
    }
    return Graph;
}

void addEdge(graph *Graph, int source, int destination){
    node *newVertex = makeNode(destination);
    newVertex->next = Graph->adjLists[source];
    Graph->adjLists[source] = newVertex;

    newVertex = makeNode(source);
    newVertex->next = Graph->adjLists[destination];
}

void BFS(graph *Graph, int start){
    int queue[Graph->numOfVertices];
    int front = 0, rear = 0;
    int visited[Graph->numOfVertices];
    for(int i = 0; i < Graph->numOfVertices; i++){
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[rear++] = start; //push to queue

    while(front != rear){
        int cur = queue[front++]; //pop
        printf("%d ", cur);

        node *temp = Graph->adjLists[cur];
        while(temp != NULL){
            int neighbour = temp->data;
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                queue[rear++] = neighbour; //push to queue
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void DFS(graph *Graph, int start){
    int stack[Graph->numOfVertices];
    int top = 0;
    int visited[Graph->numOfVertices];
    for(int i = 0; i < Graph->numOfVertices; i++){
        visited[i] = 0;
    }
    visited[start] = 1;
    stack[top++] = start; //push

    while(top != 0){
        int cur = stack[--top]; //pop
        printf("%d ", cur);

        node *temp = Graph->adjLists[cur];
        while(temp != NULL){
            int neighbour = temp->data;
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                stack[top++] = neighbour; //push
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main(){
    graph *Graph = initializeGraph(5);
    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 2);
    addEdge(Graph, 1, 3);
    addEdge(Graph, 1, 4);
    addEdge(Graph, 2, 4);
    BFS(Graph, 0);
    DFS(Graph, 0);
    return 0;
}