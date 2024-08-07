#include<stdio.h>
#define V 4

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V]) { 
    int dist[V][V], i, j, k;
    
    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the solution matrix by considering all vertices
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

void printSolution(int dist[][V]) {
    int i, j;
    printf("Following matrix shows the shortest distances between every pair of vertices\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == 9999) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 5, 9999, 10},
        {9999, 0, 3, 9999},
        {9999, 9999, 0, 1},
        {9999, 9999, 9999, 0}
    };

    floydWarshall(graph);
    return 0;
}

