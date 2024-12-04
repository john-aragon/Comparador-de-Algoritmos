#include <stdio.h>
#include <time.h>
#define max 400000

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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
