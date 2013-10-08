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

void swap(int arr[], int i, int j)
{
	int t;

	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

int partion(int arr[], int p, int r)
{
	int i = p - 1;
	int x = arr[r];
	int j;

	for (j = p; j < r; ++j)
		if (arr[j] < x) 
			swap(arr, ++i, j);

	swap(arr, ++i, r);

	return i;
}

void _qsort(int arr[], int p, int r)
{
	if (p < r) {
		int pivot = partion(arr, p, r);
		_qsort(arr, p, pivot - 1);
		_qsort(arr, pivot + 1, r);
	}
}

int main(int argc, char **argv)
{
	int i, arr[16];

	srand(time(NULL));

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		arr[i] = rand() % 100;

	_qsort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		fprintf(stdout, "%d ", arr[i]);
	fprintf(stdout, "\n");

	return EXIT_SUCCESS;
}
