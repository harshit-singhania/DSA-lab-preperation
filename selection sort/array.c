// selection sort in array 

#include <stdio.h> 

void selectionSort(int array[], int size) 
{ 
    for (int step = 0; step < size - 1; step++) 
    { 
        int min_idx = step; 
        for (int i = step + 1; i < size; i++) 
        { 
            // To sort in descending order, change > to < in this line. 
            // Select the minimum element in each loop. 
            if (array[i] < array[min_idx]) 
                min_idx = i; 
        } 
        // put min at the correct position 
        int temp = array[step]; 
        array[step] = array[min_idx]; 
        array[min_idx] = temp; 
    } 
}

// Driver code

int main() 
{ 
    int data[] = {20, 12, 10, 15, 2}; 
    int size = sizeof(data) / sizeof(data[0]); 
    selectionSort(data, size); 
    printf("Sorted array in ascending order: \n"); 
    for (int i = 0; i < size; i++) 
        printf("%d ", data[i]); 
    return 0; 
}

