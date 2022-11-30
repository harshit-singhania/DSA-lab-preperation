// linear search in array 

#include <stdio.h>

int linear_search(int arr[], int item) {
    int i;
    int n = sizeof(arr)/sizeof(arr[0]);
    for (i = 0; i < n; i++) {
        if (arr[i] == item) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int item = 5;
    int index = linear_search(arr, item);
    if (index == -1) {
        printf("Item not found");
    } else {
        printf("Item found at index %d", index);
    }
    return 0;
}

