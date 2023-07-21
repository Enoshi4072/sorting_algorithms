#include "sort.h"

/**
 * bubble_sort - Sorts an array of ints in ascending order
 * @array: Arry to sort
 * @size: The length of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp_hold;

if (size < 2 || array == NULL)
	return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp_hold = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp_hold;
				print_array(array, size);
			}
		}
	}
}
