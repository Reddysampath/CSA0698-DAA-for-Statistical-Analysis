#include <stdio.h>

void containerLoader(int weights[], int n, int capacity) {
    int i, totalWeight = 0;
    for (i = 0; i < n; i++) {
        if (totalWeight + weights[i] <= capacity)
            totalWeight += weights[i];
        else break;
    }
    printf("Total weight loaded: %d\n", totalWeight);
}

int main() {
    int weights[] = {10, 20, 30, 40};
    int capacity = 50;
    int n = sizeof(weights) / sizeof(weights[0]);
    containerLoader(weights, n, capacity);
    return 0;
}

