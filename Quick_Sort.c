#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 380000

void swap(int* a, int* b);

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    clock_t start, end;
    int arr[max];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(NULL));
    
    for (int i = 0; i < max; i++)
    {
        arr[i]=rand();
    }
    
    start=clock();
    quickSort(arr, 0, n - 1);
    end=clock();

    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Tempo de execucao: %lf ms\n", time_taken);
    
    return 0;
}