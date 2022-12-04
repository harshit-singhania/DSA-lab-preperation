// Radix Sort in C Programming

#include <stdio.h>

void radix_sort(int a[], int n)
{
    int i, b[10], m = 0, exp = 1;
    for (i = 0; i < n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }
    while (m / exp > 0)
    {
        int bucket[10] = {0};
        for (i = 0; i < n; i++)
        {
            bucket[a[i] / exp % 10]++;
        }
        for (i = 1; i < 10; i++)
        {
            bucket[i] += bucket[i - 1];
        }
        for (i = n - 1; i >= 0; i--)
        {
            b[--bucket[a[i] / exp % 10]] = a[i];
        }
        for (i = 0; i < n; i++)
        {
            a[i] = b[i];
        }
        exp *= 10;
    }
}

int main()
{
    int a[100], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    radix_sort(a, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

