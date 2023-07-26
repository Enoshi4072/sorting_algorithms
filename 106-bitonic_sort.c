#include "sort.h"

/**
 * swap - Swaps two integer values.
 *
 * @a: Pointer to the first value.
 * @b: Pointer to the second value.
 */
void swap(int *a, int *b)
{
int temp_hold;
temp_hold = *a;
*a = *b;
*b = temp_hold;
}

/**
 * bitonic_merge - Performs a bitonic merge on the array.
 *
 * @array: The array to be merged.
 * @size: The size of the array.
 * @start: The starting index of the merge.
 * @count: The number of elements to be merged.
 * @dir: The direction of the merge (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t count, int dir)
{
size_t k, i;

if (count > 1)
{
k = count / 2;
printf("Merging [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
print_array(array + start, count);

for (i = start; i < start + k; i++)
{
if ((array[i] > array[i + k]) == dir)
{
swap(&array[i], &array[i + k]);
}
}
bitonic_merge(array, size, start, k, dir);
bitonic_merge(array, size, start + k, k, dir);
}
}
/**
 * b_recursive - Recursively performs bitonic sort on the array.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @start: The starting index of the sort.
 * @count: The number of elements to be sorted.
 * @dir: The direction of the sort (1 for ascending, 0 for descending).
 */
void b_recursive(int *array, size_t size, size_t start, size_t count, int dest)
{
size_t k;
if (count > 1)
{
k = count / 2;
b_recursive(array, size, start, k, 1);
b_recursive(array, size, start + k, k, 0);

bitonic_merge(array, size, start, count, dest);
}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
b_recursive(array, size, 0, size, 1);
}
