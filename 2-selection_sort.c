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
	size_t i = 0, j = 0, min_idx = 0;
	int min;

	while (i < size)
	{
		j = i;
		min = array[j];
		min_idx = j;
		while (j < size)
		{
			if (array[j] < min)
				min_idx = j, min = array[j];
			j++;
		}
		if (array[i] != array[min_idx])
		{
			swap(array + min_idx, array + i);
			print_array(array, size);
		}
		i++;
	}
}
