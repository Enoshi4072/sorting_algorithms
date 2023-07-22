#include "sort.h"

/**
 * selection_sort - Sorts an array of ints in ascending order
 * using the selection sort algo
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
size_t i, l_index, j;
int temp_hold;
if (array == NULL || size <= 1)
	return;

for (i = 0; i < size - 1; i++)
{
l_index = i;

for (j = i + 1; j < size; j++)
{
if (array[j] < array[l_index])
	l_index = j;
}
if (l_index != i)
{
temp_hold = array[i];
array[i] = array[l_index];
array[l_index] = temp_hold;
print_array(array, size);
}
}
}
