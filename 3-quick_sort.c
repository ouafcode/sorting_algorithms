#include <stdio.h>
#include "sort.h"


/**
 * position - to change position of numbers
 * @array: input array
 * @nbr1: first number
 * @nbr2: second number
 * @size: input size
 */
void position(int *array, int *nbr1, int *nbr2, size_t size)
{
	int pst = *nbr1;

	*nbr1 = *nbr2;
	*nbr2 = pst;
	print_array(array, size);
}

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

	int pivot = array[ub];
	int index  = lb;
	int i = 0;

	for (i = lb; i < ub; i++)
	{
		if (array[i] <= pivot)
		{
			if (index != i)
				position(array, &array[i], &array[index], size);
			index++;
		}
	}
	if (index != ub)
		position(array, &array[ub], &array[index], size);
	return (index);

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
