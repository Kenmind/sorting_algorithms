#include "sort.h"

/**
 * swap - Swaps two elements.
 * @a: Pointer to first integer
 * @b: Pointer to secondinteger
 */

void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;

}

/**
 * partition - Partitions the array arr
 * @arr: Array to be partitioned
 * @low: The lower value member
 * @high: The higher value member
 * @size: size of the array
 * Return: The lowest value member
 */

int partition(int *arr, int low, int high, size_t size)
{
	int p;
	int i = low;
	int j;

	p = arr[high];
	for (j = low; j < high; j++)
	{
		if (arr[j] <= p)
		{

			swap(&arr[i], &arr[j]);


			if (i != j)
				print_array(arr, size);

			i++;

		}
	}

	swap(&arr[i], &arr[high]);
	if (i != j)
		print_array(arr, size);

	return (i);
}

/**
 * quickSort - Sorts an array using quick sort algorithm
 * @arr: Array to sort
 * @low: The lower value
 * @high: The higher value
 * @size: Size of the array arr
 */

void quickSort(int *arr, int low, int high, size_t size)
{

	int p;

	if (low < high)
	{
		p = partition(arr, low, high, size);
		quickSort(arr, low, p - 1, size);
		quickSort(arr, p + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array using quick sort algorithm
 * @array: array to sort
 * @size: size of array
 **/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
