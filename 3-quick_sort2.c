#include "sort.h"

/**
 * swap - Swap two ints
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void swap(int *a, int *b)
{
int temp_hold;
temp_hold = *a;
*a = *b;
*b = temp_hold;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 *
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 * @a: Starting index of the partition
 * @b: Ending index of the partition
 *
 * Return: Final position of the pivot
 */

int lomuto_partition(int *array, size_t size, int a, int b)
{
int *pivot;
int top, bottom;

pivot = array + b;
top = bottom = a;

while (bottom < b)
{
if (array[bottom] < *pivot)
{
if (top < bottom)
{
swap(array + bottom, array + top);
print_array(array, size);
}
top++;
}
bottom++;
}
if (array[top] > *pivot)
{
swap(array + top, pivot);
print_array(array, size);
}
return (top);
}

/**
 * quick_sort_recur - Recursive function for
 * Quick sort using Lomuto partition
 *
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 * @a: Starting index of the partition
 * @b: Ending index of the partition
 */

void quick_sort_recur(int *array, size_t size, int a, int b)
{
int partition;
if (a < b)
{
partition = lomuto_partition(array, size, a, b);
quick_sort_recur(array, size, a, partition - 1);
quick_sort_recur(array, size, partition + 1, b);
}
}

/**
 * quick_sort - Sorts an array of integers
 * in ascending order using Quick sort
 *
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
if (array == NULL || size <= 1)
	return;
quick_sort_recur(array, size, 0, size - 1);
}
