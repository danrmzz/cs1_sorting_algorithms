#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int mid, int r);

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

    mergeSort(arr, 0, n-1);

    printf("After: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);      

    free(arr);

    return 0;
}


void mergeSort(int arr[], int l, int r) {

    if (r > l) {

        int mid = (l + r) / 2;

        mergeSort(arr, l, mid); // Call mergeSort for first half
        mergeSort(arr, mid+1, r); // Call mergeSort for second half
        merge(arr, l, mid, r); // Merge the two halves
    }
}

void merge(int arr[], int l, int mid, int r) {

    int i, j, k;
    int n1 = mid - l + 1; // Size of left array
    int n2 = r - mid; // Size of right array

    // Create temp arrays
    int* L = (int*) malloc(n1 * sizeof(int));
    int* R = (int*) malloc(n2 * sizeof(int));

    // Copy data to temp array
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = l;

    // Merge L and R into arr
    while (i < n1 || j < n2) {
        if (j == n2 || (i < n1 && L[i] < R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    free(L);
    free(R);
}