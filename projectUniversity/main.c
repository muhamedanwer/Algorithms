#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int arr[], int l, int m,int r);
void mergeSort(int arr[], int l, int r);
void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
void fill(int arr[], int n);

int main(){

	srand(time(0));

	int sizes[] = {1000, 2000, 3000, 4000};
    int itemSize = sizeof(sizes) / sizeof(sizes[0]);

    for(int i=0; i < itemSize; i++){
        int n = sizes[i];
        int arr[n];
        fill(arr, n);

        clock_t start1 = clock();
        selectionSort(arr, n);
        clock_t end1 = clock();
		double time_selection = ((double)(end1 - start1)) / CLOCKS_PER_SEC;

		clock_t start2 = clock();
		mergeSort(arr,0, n-1);
		clock_t end2 = clock();

        double time_merge = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
        printf("Selection Sort with an array of size %d: %f sec\n", n, time_selection);
        printf("Merge Sort with an array of size %d: %f sec\n", n, time_merge);
    }
    return 0;

}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void selectionSort(int arr[], int n){
    int i, j, min;
    for(i =0; i < n; i++){
        min = i;
        for(j= i+1; j < n; j++){
            if(arr[j] < min){
                min = arr[j];
            }
        }
        swap(&arr[min], &arr[i]);
    }
}


void fill(int arr[], int n){
    for(int i=0; i < n; i++){
        arr[i] = rand() % 10000; // randoom number between 0 & 9999
    }
}
