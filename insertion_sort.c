#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n);

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

    insertionSort(arr, n);

    printf("After: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);      

    free(arr);

    return 0;
}


void insertionSort(int arr[], int n) {

    int i, j, hand;
    
    // i starts from 1 so that we can compare it with item at 0. See, j starts from i-1 in the next loop
    for (i = 1; i < n; i++) {

        hand = arr[i]; // Take the item in hand

        for(j = i-1; j >= 0; j--){

            if (arr[j] > hand)
                arr[j+1] = arr[j]; // Shift the item
            else
                break; // arr[j] is already in correct place and all its previous items are already sorted in reference to the item in your hand
        }
        /* If the loop breaks for j becoming -1, we put the item in 0. Otherwise,
        the loop is breaking for the break statement. Put the item in hand after j (the
        remaining items were shifted forward already, if needed. */
        arr[j+1] = hand; 
    }
}