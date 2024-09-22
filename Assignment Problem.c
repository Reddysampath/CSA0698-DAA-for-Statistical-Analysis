#include <stdio.h>
#include <limits.h>

#define N 4  

int min(int a, int b) {
    return (a < b) ? a : b;
}

int findMinCost(int cost[N][N], int assigned[N], int assignments[N], int worker, int totalCost, int bestAssignments[N], int *minCost) {
    int task;
    if (worker == N) {
        int i;
        if (totalCost < *minCost) {
            *minCost = totalCost;
            for (i = 0; i < N; i++) {
                bestAssignments[i] = assignments[i];
            }
        }
        return totalCost;
    }

    for (task = 0; task < N; task++) {
        if (!assigned[task]) {
            assigned[task] = 1;
            assignments[worker] = task;
            findMinCost(cost, assigned, assignments, worker + 1, totalCost + cost[worker][task], bestAssignments, minCost);
            assigned[task] = 0;
        }
    }
    return *minCost;
}

int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int assigned[N] = {0};
    int assignments[N] = {0};
    int bestAssignments[N] = {0};
    int minCost = INT_MAX;
    int i;

    findMinCost(cost, assigned, assignments, 0, 0, bestAssignments, &minCost);

    printf("Minimum cost: %d\n", minCost);
    printf("Best Assignments (Worker -> Task):\n");
    for (i = 0; i < N; i++) {
        printf("Worker %d -> Task %d\n", i, bestAssignments[i]);
    }

    return 0;
}

