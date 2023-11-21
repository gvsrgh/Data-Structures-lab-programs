#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int item) {
    if(top >= SIZE-1) {
        printf("\nStack Overflow.");
    }
    else {
        stack[++top] = item;
    }
}

int pop() {
    if(top < 0) {
        printf("\nStack Underflow.");
        return 0;
    }
    else {
        int item = stack[top--];
        return item;
    }
}

void DFS(int** graph, int start, int* visited, int size) {
    push(start);

    while(top != -1) {
        int v = pop();

        if(visited[v] == 0) {
            printf("%d ", v);
            visited[v] = 1;
        }

        for(int i = 0; i < size; i++) {
            if(graph[v][i] == 1 && visited[i] == 0) {
                push(i);
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

    DFS(graph, start, visited, size);

    for(int i = 0; i < size; i++) {
        free(graph[i]);
    }
    free(graph);
    free(visited);

    return 0;
}
