#include "sort.h"

/**
 * swap - swaps integers and prints the array
 * @x: Pointer to first integer
 * @y: Pointer to second integer
 *
 */

void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * selection_sort - sorts an array using slection sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;
		swap(array + min_idx, array + i);
		print_array(array, size);
	}
}
