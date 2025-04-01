#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int n, m; // n = number of vertices, m = number of colors
int G[MAX][MAX]; // Adjacency matrix
int x[MAX]; // Color assignments
int minColors = MAX; // Minimum colors required
int solutions[MAX][MAX]; // Stores minimal color solutions
int solCount = 0; // Counter for minimal solutions

// Function to check if the color assignment is valid
bool isSafe(int k, int c) {
    for (int j = 1; j <= n; j++) {
        if (G[k][j] && x[j] == c) {
            return false; // Adjacent vertices have the same color
        }
    }
    return true;
}

// Function to find the next valid color
void NextValue(int k) {
    do {
        x[k] = (x[k] + 1) % (m + 1); // Assign the next color
        if (x[k] == 0) return; // All colors tried, backtrack
    } while (!isSafe(k, x[k]));
}

// Recursive function for m-coloring problem
void mColoring(int k) {
    do {
        NextValue(k); // Assign a valid color
        if (x[k] == 0) return; // No color found, backtrack
        if (k == n) { // All vertices colored
            // Count the number of unique colors used
            int colorSet[MAX] = {0};
            int usedColors = 0;
            for (int i = 1; i <= n; i++) {
                if (colorSet[x[i]] == 0) {
                    colorSet[x[i]] = 1;
                    usedColors++;
                }
            }

            // Print the solution
            for (int i = 1; i <= n; i++) {
                printf("%d ", x[i]);
            }
            printf("(Used Colors: %d)\n", usedColors);

            // Track minimum color solutions
            if (usedColors < minColors) {
                minColors = usedColors;
                solCount = 0; // Reset minimal solution count
            }
            if (usedColors == minColors) {
                for (int i = 1; i <= n; i++) {
                    solutions[solCount][i] = x[i];
                }
                solCount++;
            }
        } else {
            mColoring(k + 1); // Recur for the next vertex
        }
    } while (true);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of colors: ");
    scanf("%d", &m);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) x[i] = 0; // Initialize color assignments

    printf("\nAll Coloring Solutions:\n");
    mColoring(1);

    printf("\nMinimal Coloring Solutions (Using %d Colors):\n", minColors);
    for (int i = 0; i < solCount; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", solutions[i][j]);
        }
        printf("\n");
    }

    return 0;
}
