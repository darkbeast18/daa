#include <stdio.h>
#define INF 1000000
#define MAX 100

void floydWarshall(int dist[MAX][MAX], int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("\nShortest distances between all pairs:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, E;
    int dist[MAX][MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (u < 1 || u > V || v < 1 || v > V) {
            printf("Invalid edge: vertices out of bounds.\n");
            continue;
        }
        dist[u - 1][v - 1] = w;
    }

    floydWarshall(dist, V);

    return 0;
}
