#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into one sorted array.
 * @array: The original array to be sorted.
 * @left: The left sub-array.
 * @left_size: The size of the left sub-array.
 * @right: The right sub-array.
 * @right_size: The size of the right sub-array.
 */

void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
size_t i = 0, j = 0, k = 0, x;
int *temp_array;

temp_array = malloc((left_size + right_size) * sizeof(int));

if (temp_array == NULL)
{
printf("Error: Memory allocation failed\n");
exit(EXIT_FAILURE);
}

printf("Merging...\n[left]: ");
print_array(left, left_size);
printf("[right]: ");
print_array(right, right_size);

while (i < left_size && j < right_size)
{
if (left[i] <= right[j])
{
temp_array[k] = left[i];
i++;
}
else
{
temp_array[k] = right[j];
j++;
}
k++;
}

while (i < left_size)
{
temp_array[k] = left[i];
i++;
k++;
}

while (j < right_size)
{
temp_array[k] = right[j];
j++;
k++;
}
for (x = 0; x < (left_size + right_size); x++)
array[x] = temp_array[x];

printf("[Done]: ");
print_array(array, left_size + right_size);

free(temp_array);
}

/**
 * merge_sort_recursive - Recursive function for Merge sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */

void merge_sort_recursive(int *array, size_t size)
{
	int *left, *right;
	size_t mid, i;

if (size <= 1)
return;

mid = size / 2;

left = (int *)malloc(mid * sizeof(int));
right = (int *)malloc((size - mid) * sizeof(int));

if (left == NULL || right == NULL)
{
printf("Error: Memory allocation failed\n");
exit(EXIT_FAILURE);
}

for (i = 0; i < mid; i++)
left[i] = array[i];

for (i = mid; i < size; i++)
right[i - mid] = array[i];

merge_sort_recursive(left, mid);
merge_sort_recursive(right, size - mid);

merge(array, left, mid, right, size - mid);
free(left);
free(right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * Merge sort algorithm (top-down approach).
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void merge_sort(int *array, size_t size)
{
if (array == NULL || size <= 1)
return;
merge_sort_recursive(array, size);
}
