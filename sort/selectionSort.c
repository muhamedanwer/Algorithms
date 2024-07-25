#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("time taken to sort an array of size %d: %f sec\n", n, time_taken);
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