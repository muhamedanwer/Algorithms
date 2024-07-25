#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to fill an array with random values
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random values between 0 and 9999
    }
}

int main() {
    srand(time(0));

    // Array sizes to test
    int sizes[] = {1000, 2000, 3000, 4000, 5000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    // Measure and print the time taken for each array size
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int arr[n];
        fillArray(arr, n);

        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort array of size %d: %f seconds\n", n, time_taken);
    }

    return 0;
}
