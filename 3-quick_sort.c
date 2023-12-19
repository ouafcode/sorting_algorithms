#include <stdio.h>
#include "sort.h"


/**
 * Partition - partition of array
 * @array: input array
 * @lb: array start
 * @ub: array end
 * @size: input size
 * Return: location of pivot
 */

int Partition(int *array, int lb, int ub, size_t size)
{
	int pivot, start, end, temp;

	pivot = array[lb];
	start = lb;
	end = ub;

	while (start < end)
	{
		while (array[start] <= pivot)
		{
			start++;
		}
		while (array[end] > pivot)
		{
			end--;
		}
		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			print_array(array, size);
		}
	}
	temp = array[lb];
	array[lb] = array[end];
	array[end] = temp;
	print_array(array, size);
	return (end);
}


/**
 * Quick - sort array of integers in ascending order
 * @array: input array
 * @lb: start array
 * @ub: end array
 * @size : array size
 */

void Quick(int *array, int lb, int ub, size_t size)
{
	if (lb < ub)
	{
		int loc = 0;

		loc = Partition(array, lb, ub, size);
		Quick(array, lb, loc - 1, size);
		Quick(array, loc + 1, ub, size);
	}
}


/**
 * quick_sort - sort array of integers in ascending order
 * @array: input array
 * @size: input size array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	Quick(array, 0, size - 1, size);
}
