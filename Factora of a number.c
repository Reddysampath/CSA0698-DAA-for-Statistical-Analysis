#include <stdio.h>
void printFactors(int n) {
	int i;
    for ( i = 1; i <= n; i++) {
        if (n % i == 0)
            printf("%d ", i);
    }
}
int main() {
    int n ;
    printf("Enter the number:\n");
    scanf("%d",&n);
    printFactors(n);
    return 0;
}

