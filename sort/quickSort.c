#include <stdio.h>


void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int &arr[], int low, int high){

    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i<j){
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }
        while (arr[i] <= pivot && j >= low){
            j--;
        }
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int index = partition(arr, low, high);

        quickSort(arr, low, index-1);
        quickSort(arr, index+1, high);
    }
}