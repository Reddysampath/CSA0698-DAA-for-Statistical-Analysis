#include <stdio.h>
#include <limits.h>

int sum(int freq[], int low, int high) {
    int sum = 0,k;
    for ( k = low; k <= high; k++)
        sum += freq[k];
    return sum;
}

int minCostBST(int keys[], int freq[], int n) {
    int cost[n][n],i,length,r;
    
    for ( i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for ( length = 2; length <= n; length++) {
        for (i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            for ( r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r-1] : 0) +
                        ((r < j) ? cost[r+1][j] : 0) +
                        sum(freq, i, j);

                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n-1];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = 3;

    printf("Cost of Optimal BST is: %d\n", minCostBST(keys, freq, n));
    return 0;
}

