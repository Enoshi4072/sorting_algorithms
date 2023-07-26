#include "sort.h"

/**
 * find_max - Finds the maximum element in the array.
 *
 * @array: The array to search.
 * @size: The size of the array.
 *
 * Return: The maximum element in the array.
 */
int find_max(int *array, size_t size)
{
int max;
size_t i;
max = array[0];

for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
 * counting_sort_radix- Sorts the array based on a specific
 * significant digit using Counting Sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The exponent of the specific significant digit.
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
int *output;
size_t i;
int j;
int count[10] = {0};
output = malloc(size * sizeof(int));

if (output == NULL)
{
printf("Error: Memory allocation failed\n");
exit(EXIT_FAILURE);
}

for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;

for (j = 1; j < 10; j++)
count[j] += count[j - 1];

for (j = size - 1; j >= 0; j--)
{
output[count[(array[j] / exp) % 10] - 1] = array[j];
count[(array[j] / exp) % 10]--;
}

for (i = 0; i < size; i++)
array[i] = output[i];

print_array(array, size);

free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
int max_v;
int multi;
max_v = find_max(array, size);


for (multi = 1; max_v / multi > 0; multi *= 10)
counting_sort_radix(array, size, multi);
}
