// Topological Sort
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define MIN -1
#define INF 999

typedef struct Graph {
    int V;
    int E;
    int adj[MAX][MAX];
} Graph;
typedef struct Queue {
    int items [MAX];
    int front;
    int rear;
} Queue;
void initGraph(Graph* g, int v, int e) {
    g->V = v;
    g->E = e;
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            g->adj[i][j] = 0;
        }


    }

}
void addEdge(Graph* g, int src, int dest){
    g->adj[src][dest] = 1;

}
void information(Graph* g){
    printf("Number of Vertices: %d\n", g->V);
    printf("Number of Edges: %d\n", g->E);
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < g->V; i++){
        for(int j = 0; j < g->V; j++){
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue* q){
    if(q->rear == -1)
        return 1;
    else
        return 0;
}
void enqueue(Queue* q, int value){
    if(q->rear == MAX - 1)
        printf("Queue is Full\n");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}
void topologicalSort(Graph* g) {
    int inDegree[MAX] = {0};
    for(int i = 0; i < g->V; i++) {
        for(int j = 0; j < g->V; j++) {
            if(g->adj[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
    Queue q;
    initQueue(&q);
    for(int i = 0; i < g->V; i++) {
        if(inDegree[i] == 0) {
            enqueue(&q, i);
        }
    }
    printf("Topological Sort Order: ");
    while(!isEmpty(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);
        for(int v = 0; v < g->V; v++) {
            if(g->adj[u][v] == 1) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }
    printf("\n");                           
}
int main() {
    Graph g;
    int vertices = 6;
    int edges = 6;
    initGraph(&g, vertices, edges);
    addEdge(&g, 5, 2);
    addEdge(&g, 5, 0);
    addEdge(&g, 4, 0);
    addEdge(&g, 4, 1);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 1);
    information(&g);
    topologicalSort(&g);
    return 0;
}