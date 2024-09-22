#include <stdio.h>

int isSubsetSum(int set[], int n, int sum) {
    if (sum == 0) return 1;
    if (n == 0 && sum != 0) return 0;
    
    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum);
    
    return isSubsetSum(set, n-1, sum) || 
           isSubsetSum(set, n-1, sum-set[n-1]);
}

int main() {
    int n, sum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n],i;
    printf("Enter the elements of the set:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the sum: ");
    scanf("%d", &sum);
    if (isSubsetSum(set, n, sum))
        printf("Found a subset with given sum\n");
    else
        printf("No subset with given sum\n");

    return 0;
}

