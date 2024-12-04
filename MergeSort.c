#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 250000

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

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

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    clock_t start, end;
    int arr[max];
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    srand((unsigned)time(NULL));

    for (int i = 0; i < max; i++) {
        arr[i] = rand() % max;
    }

    start = clock();
    mergeSort(arr, 0, arr_size - 1);
    end = clock();

    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Tempo de execucao: %lf ms\n", time_taken);

    return 0;
}
