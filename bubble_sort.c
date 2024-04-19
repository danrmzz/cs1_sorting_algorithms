#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);

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

    bubbleSort(arr, n);

    printf("After: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);      

    free(arr);

    return 0;
}


void bubbleSort(int arr[], int n) {

    int i, j, temp;

    for (i = 0; i < n-1; i ++) { // Loop through all elements except last
        // Last i elements are already in place, so stop j before n-i
        // As we will compare j with j+1, we will stop j before n-1-i
        for (j = 0; j < n-1-i; j++) { 
            if (arr[j] > arr[j+1]) {

                // Swap the two elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}