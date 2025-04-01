#include <stdio.h>
#include <stdbool.h>
#define MAX 10
int graph[MAX][MAX], path[MAX], N;
bool foundCycle = false;
bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}
void findHamiltonianCycle(int pos) {
    if (pos == N) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            foundCycle = true;
            printf("Hamiltonian Cycle: ");
            for (int i = 0; i < N; i++)
                printf("%d -> ", path[i]);
            printf("%d\n", path[0]);
        }
        return;
    }
    for (int v = 1; v < N; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            findHamiltonianCycle(pos + 1);
            path[pos] = -1;
        }
    }
}
void hamiltonianCycle() {
    for (int i = 0; i < N; i++) path[i] = -1;
    path[0] = 0;
    foundCycle = false;

    findHamiltonianCycle(1);

    if (!foundCycle) {
        printf("No Hamiltonian Cycle found.\n");
    }
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &N);

    printf("Enter adjacency matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &graph[i][j]);

    hamiltonianCycle();
    return 0;
}
