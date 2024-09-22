#include <stdio.h>

int binomialCoeff(int n, int k) {
    int C[n + 1][k + 1],i,j;

    for ( i = 0; i <= n; i++) {
        for ( j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main() {
    int n,k;
    printf("Enter the n and k value:");
    scanf("%d %d",&n,&k);
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, binomialCoeff(n, k));
    return 0;
}

