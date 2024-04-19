#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);

int main(void) {

    int n;
    printf("How many numbers?\n");
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));

    
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);


    printf("Before: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    quickSort(arr, 0, n-1);

    printf("After: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);      

    free(arr);

    return 0;
}


void quickSort(int arr[], int l, int r) {

    if (l < r) {

        int k = partition(arr, l, r);

        quickSort(arr, l, k-1); // Before k
        quickSort(arr, k+1, r); // After k
    }
}

int partition(int arr[], int l, int r) {

    int pivot = l; // Stores lowest index in range
    l++; // Starts l at second value

    while (l <= r) { // Loops until l and r cross

        // Find next item on left that is too big
        while (l <= r && arr[l] <= arr[pivot])
            l++;

        // Find the next item on right that is too small
        while (r >= l && arr[r] > arr[pivot])
            r--;

        // If these items are out of place, swap them
        if (l < r) {

            int temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp; 
        }          
    }

    // Swap the partition value into its correct location
    int temp = arr[r];
    arr[r] = arr[pivot];
    arr[pivot] = temp;      

    return r; // This is the index storing the partition element   
}