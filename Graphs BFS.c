#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if(rear == SIZE-1) {
        printf("\nQueue is Full!!");
    }
    else {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
    }
}

int dequeue() {
    if(front == -1 || front > rear) {
        printf("\nQueue is Empty!!");
        return 0;
    }
    else {
        int item = queue[front];
        front++;
        if(front > rear) {
            front = rear = -1;
        }
        return item;
    }
}

void BFS(int** graph, int* visited, int size) {
    for(int start = 0; start < size; start++) {
        if(visited[start] == 0) {
            enqueue(start);
            visited[start] = 1;

            while(front != -1) {
                int v = dequeue();
                printf("%d ", v);

                for(int i = 0; i < size; i++) {
                    if(graph[v][i] == 1 && visited[i] == 0) {
                        enqueue(i);
                        visited[i] = 1;
                    }
                }
            }
        }
    }
}


int main() {
    int size;
    printf("Enter the size of the graph: ");
    scanf("%d", &size);

    int** graph = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++) {
        graph[i] = (int*)malloc(size * sizeof(int));
    }
    int* visited = (int*)malloc(size * sizeof(int));

    printf("Enter the adjacency matrix: \n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for(int i = 0; i < size; i++) {
        visited[i] = 0;
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    BFS(graph, visited, size);


    for(int i = 0; i < size; i++) {
        free(graph[i]);
    }
    free(graph);
    free(visited);

    return 0;
}
