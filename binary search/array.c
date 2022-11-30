// binary search in array 

int iterative(int arr[], int start, int end, int item) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == item) {
            return mid;
        } else if (arr[mid] > item) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int recursive(int arr[], int start, int end, int item) {
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == item) {
        return mid;
    } else if (arr[mid] > item) {
        return recursive(arr, start, mid - 1, item);
    } else {
        return recursive(arr, mid + 1, end, item);
    }
} 

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int item = 5;
    int index = iterative(arr, 0, 9, item);
    if (index == -1) {
        printf("Item not found");
    } else {
        printf("Item found at index %d", index);
    }
    return 0;
}

