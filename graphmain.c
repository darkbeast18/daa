#include <stdio.h>
#define MAX 100

int n, m;
int G[MAX][MAX];
int x[MAX];

void write() {
    printf("Solution: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}
void NextValue(int k) {
    while (1) {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;

        int j;
        for (j = 1; j <= n; j++) {
            if (G[k][j] != 0 && x[k] == x[j])
                break;
        }
        if (j == n + 1)
            return;
    }
}
void mColoring(int k) {
    while (1) {
        NextValue(k);
        if (x[k] == 0)
            return;
        if (k == n)
            write();
        else
            mColoring(k + 1);
    }
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of colors: ");
    scanf("%d", &m);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
    printf("\nColoring solutions:\n");
    mColoring(1);
    return 0;
}
