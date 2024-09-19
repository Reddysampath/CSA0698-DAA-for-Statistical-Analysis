#include<stdio.h>
int reverse(int num) {
    if (num == 0) {
        return 0; 
    }
    int rem = num % 10;
    return (rem * rem * rem) + reverse(num / 10); 
}

bool armstrong(int num) {
    return reverse(num) == num; 
}

int main() {
    int n;
    printf("Enter the number:\n");
    scanf("%d", &n);
    
    if (armstrong(n)) {
        printf("Armstrong number");
    } else {
        printf("Not an Armstrong number");
    }
    
    return 0;
}

