#include "sort.h"

/**
 * swap - Swaps two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */

void swap(int *a, int *b)
{
int temp_hold;
temp_hold = *a;
*a = *b;
*b = temp_hold;
}

/**
 * sift_down - Sifts down an element in
 * the heap to maintain the heap property.
 *
 * @array: The array to be sifted down.
 * @top: The index of the element to sift down.
 * @bottom: The index of the last element in the heap.
 * @size: The size of the array.
 */

void sift_down(int *array, size_t top, size_t bottom, size_t size)
{
size_t base, child, swap_index;

base = top;

while (2 * base + 1 <= bottom)
{
child = 2 * base + 1;
swap_index = base;

if (array[swap_index] < array[child])
	swap_index = child;

if (child + 1 <= bottom && array[swap_index] < array[child + 1])
	swap_index = child + 1;

if (swap_index == base)
	return;

swap(&array[base], &array[swap_index]);
base = swap_index;
print_array(array, size);
}
}

/**
 * heap_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */

void heap_sort(int *array, size_t size)
{
int i;

for (i = size / 2 - 1; i >= 0; i--)
sift_down(array, i, size - 1, size);

for (i = size - 1; i > 0; i--)
{
swap(&array[0], &array[i]);
print_array(array, size);
sift_down(array, 0, i - 1, size);
}
}
