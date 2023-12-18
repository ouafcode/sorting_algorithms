#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort -  sorts an array of integers  in ascending order
 * @array: input array
 * @size: size of array
 *
 * Return: print array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;
	int flag = 0;


	if (size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
