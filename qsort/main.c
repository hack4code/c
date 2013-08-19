/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/26/2013 10:48:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *        Author:  wartalker
 *        Company: fly@sky 
 *
 * =====================================================================================
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
partion(int arr[], int p, int r) {
    int i = p - 1;
    int x = arr[r];
    int j, t;

    for (j = p; j < r; ++j)
        if (arr[j] < x) {
            ++i;
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }

    arr[r] = arr[i+1];
    arr[i+1] = x;

    return i + 1;
}

void
_qsort(int arr[], int p, int r) {
    if (p < r) {
        int pivot = partion(arr, p, r);
        _qsort(arr, p, pivot - 1);
        _qsort(arr, pivot + 1, r);
    }
}

int
main(int argc, char **argv) {
    int i, arr[10];

    srand(time(NULL));

    for (i = 0; i < 10; ++i)
        arr[i] = rand() % 100;

    _qsort(arr, 0, 9);

    for (i = 0; i < 10; ++i)
        fprintf(stdout, "%d ", arr[i]);
    fprintf(stdout, "\n");

    return EXIT_SUCCESS;
}
