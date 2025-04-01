#include <stdio.h>
#define MAX 100
int w[MAX], x[MAX], n, m;
void SumOfSub(int s, int k, int r) {
    x[k] = 1;
    if (s + w[k] == m) {
        printf("Subset found: { ");
        for (int i = 1; i <= k; i++) {
            if (x[i])
                printf("%d ", w[i]);
        }
        printf("}\n");
    } else if ((s + w[k] + w[k + 1]) <= m) {
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }

    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k]);
    }
}

int main() {
    int total = 0;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set in non-decreasing order: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        total += w[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &m);

    if (total < m) {
        printf("No solution exists as sum of all elements is less than %d\n", m);
        return 0;
    }

    SumOfSub(0, 1, total);
    return 0;
}
