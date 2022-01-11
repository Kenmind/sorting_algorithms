#include "sort.h"

/**
 * swap - swaps elements in an array
 * @x: first element
 * @y: second element
 */

void swap(int *x, int *y)
{
	int t = *x;

	*x = *y;
	*y = t;
}

/**
 * shell_sort - Sorts an array using shell sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int tmp, h;

	if (size <= 1 || !array)
		return;
	while (interval <= size)
		interval = interval * 3 + 1;
	while (interval > 0)
	{
		interval = (interval - 1) / 3;
		if (interval < 1)
			break;
		j = 0;
		while (j < interval)
		{
			i = j;
			while (i < size)
			{
				tmp = i - interval;
				h = i;
				while (tmp >= 0)
				{
					if (array[h] > array[tmp])
						break;
					swap(array + h, array + tmp);
					h = tmp;
					tmp -= interval;
				}
				i += interval;
			}
			j++;
		}
		print_array(array, size);
	}
}
