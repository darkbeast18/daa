#include <stdio.h>
#define MAX 100

int n;
int G[MAX][MAX];
int x[MAX];

void write() {
    printf("Hamiltonian Cycle: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("%d\n", x[1]); // To complete the cycle
}

int isValid(int k) {
    if (G[x[k - 1]][x[k]] == 0)
        return 0;

    for (int j = 1; j < k; j++) {
        if (x[j] == x[k])
            return 0;
    }
    return 1;
}

void NextValue(int k) {
    while (1) {
        x[k] = (x[k] % n) + 1;
        if (x[k] == 0)
            return;

        if (isValid(k)) {
            if (k == n) {
                if (G[x[n]][x[1]] != 0)
                    write();
            } else {
                NextValue(k + 1);
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }

    x[1] = 1; // Starting vertex is 1
    printf("\nHamiltonian cycles:\n");
    NextValue(2);

    return 0;
}
