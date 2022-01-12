#include "sort.h"
#include <stdbool.h>

/**
 * partition - sorts  elements into partitions and prints array
 * @low: lower value of arr
 * @high: higher value of arr
 * @arr: array to print
 * @size: size of array arr
 * Return: lowest value
 */

int partition(int *arr, size_t size, int low, int high)
{
	int pivot = arr[high], i = low - 1, j = 0, tmp = 0;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
			print_array(arr, size);
		}
	}
	tmp = arr[high];
	arr[high] = arr[i + 1];
	arr[i + 1] = tmp;
	return (i + 1);
}

/**
 * quickSort - Quick sort algorithm
 * @low: first element
 * @high: last element
 * @arr: array to sort
 * @size: size of the array
 */

void quickSort(int *arr, size_t size, int low, int high)
{
	int i;

	if (low < high)
	{
		i = partition(arr, size, low, high);
		quickSort(arr, size, low, i - 1);
		quickSort(arr, size, i + 1, high);
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
	if (array == NULL)
		return;
	quickSort(array, size, 0, size - 1);
}
