#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        *max = *min = arr[low];
        return;
    }
    
    int mid = (low + high) / 2;
    int max1, min1;
    
    findMaxMin(arr, low, mid, max, min);
    findMaxMin(arr, mid + 1, high, &max1, &min1);
    
    if (max1 > *max) *max = max1;
    if (min1 < *min) *min = min1;
}

int main() {
    int arr[] = {3, 5, 7, 52, 8};
    int max, min;
    
    findMaxMin(arr, 0, 4, &max, &min);
    
    printf("Max: %d, Min: %d\n", max, min);
    
    return 0;
}
