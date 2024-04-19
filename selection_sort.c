#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n);

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

    selectionSort(arr, n);

    printf("After: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);      

    free(arr);

    return 0;
}


void selectionSort(int arr[], int n) {

    int i, j, minIdx, temp;

    for (i = 0; i < n-1; i++) { // Loop through all elements except last which will automatically be sorted

        minIdx = i; // Assume first element is min

        for (j = i+1; j < n; j++) // Loop through all elements after i and compare
            if (arr[j] < arr[minIdx])
                minIdx = j;

        // Swap the two elements
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}