#include "sort.h"
#include <stdbool.h>

/**
 * swap - swaps elements and prints array
 * @a: pointer to first integer
 * @b: pointer to second integer
 * @arr: array to print
 * @size: size of array arr
 */

void swap(int *a, int *b, int *arr, size_t size)
{
	int p = *a;

	*a = *b;
	*b = p;
	print_array(arr, size);
}

/**
 * quickSort - Quick sort algorithm
 * @low: first element
 * @high: last element
 * @size: size of the array
 * @arr: Array to sort
 */

void quickSort(int *arr, size_t size, size_t low, size_t high)
{
	int pivot;
	size_t i = low, j = high - 1;
	bool ifound = false, jfound = false;

	if (high <= low || size <= 1)
		return;
	if (high == low + 1)
	{
		if (arr[low] > arr[high])
			swap(arr + low, arr + high, arr, size);
		return;
	}
	pivot = arr[high];
	while (i < high)
	{
		if (i >= j)
		{
			if (ifound)
				swap(arr + high, arr + j, arr, size), low++;
			else if (jfound)
				high--;
			else
				swap(arr + high, arr + i, arr, size);
			quickSort(arr, size, low, high);
			break;
		}
		if (arr[i] >= pivot)
			ifound = true;
		if (arr[j] < pivot)
			jfound = true;
		if (!ifound)
			i++;
		if (!jfound)
			j--;
		if (ifound && jfound)
		{
			swap(arr + i, arr + j, arr, size);
			ifound = false, jfound = false;
		}
	}
}

/**
 * quick_sort - Sorts an array using quick sort algorithm
 *
 * @array: Array to sort
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	quickSort(array, size, 0, size - 1);
}
