#include <stdio.h>


void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}


int optimalMerge(int files[], int n) {
    sort(files, n);
    int cost = 0;
    for (int i = 1; i < n; i++) {
        files[i] += files[i - 1];
        cost += files[i];
    }

    return cost;
}

int main() {
    int files[10], n;
    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file sizes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }

    int minCost = optimalMerge(files, n);
    printf("Minimum cost of merging is: %d Comparisons\n", minCost);
    return 0;
}

