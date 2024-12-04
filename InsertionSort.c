// C program for implementation of Insertion Sort
#include <stdio.h>
#include <time.h>
#define max 400000

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// Driver method
int main()
{
    clock_t start, end;
    int arr[max];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand((unsigned)time(NULL));

    for (int i = 0; i < max; i++)
    {
        arr[i]=rand()%max;
    }
    
    start = clock();
    insertionSort(arr, n);
    end = clock();

    double time_taken = ((double)(end-start)/CLOCKS_PER_SEC)*1000;
    printf("tempo de execucao: %lf ms\n ", time_taken);

    return 0;

}

/* This code is contributed by Hritik Shah. */