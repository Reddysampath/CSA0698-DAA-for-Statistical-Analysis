#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int target = 1;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, size - 1, target);
    if (result == -1)
        printf("Element not present in array\n");
    else
        printf("Element found at index %d\n", result);
    return 0;
}

