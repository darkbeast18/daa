#include <stdio.h>
#include <limits.h>
#define MAX 100
void bellmanFord(int edges[MAX][3], int V, int E, int src) {
    int dist[MAX];
    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
    }dist[src] = 0;
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative-weight cycle!\n");
            return;
        }
    }
    printf("Vertex \t Distance from Source\n");
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d \t INF\n", i);
        else
            printf("%d \t %d\n", i, dist[i]);
    }
}
int main() {
    int V, E;
    int edges[MAX][3];
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    int source;
    printf("Enter the source vertex (starting from 1): ");
    scanf("%d", &source);
    bellmanFord(edges, V, E, source);

}
