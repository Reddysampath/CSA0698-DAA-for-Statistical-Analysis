#include <stdio.h>
void printNumbers(int n) {
    if (n == 0)
        return;
    printNumbers(n - 1);
    printf("%d", n);
}
void printPattern(int n) {
    if (n == 0)
        return;
    printPattern(n - 1);
    printNumbers(n);
    printf("\n");
}
int main() {
    int n = 4;
    printPattern(n);
    return 0;
}
