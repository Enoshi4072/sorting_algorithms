#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
int max_value;
int *countArray, *final_Array;
int j;
size_t i;
/* Maximum value */
max_value = array[0];
for (i = 1; i < size; i++)
{
if (array[i] > max_value)
{
max_value = array[i];
}
}

/* Allocate memory */
countArray = (int *)malloc((max_value + 1) * sizeof(int));
if (countArray == NULL)
{
return;
}
final_Array = (int *)malloc(size * sizeof(int));
if (final_Array == NULL)
{
	return;
}
/* Initialize the array */
for (j = 0; j <= max_value; j++)
{
countArray[j] = 0;
}
/* Count occurrences of each element */
for (i = 0; i < size; i++)
{
countArray[array[i]]++;
}

for (j = 1; j <= max_value; j++)
{
	countArray[j] += countArray[j - 1];
}

/* Print countArray */
print_array(countArray, max_value + 1);

/* Place elements in sorted order */
for (i = 0; i < size; i++)
{
	final_Array[countArray[array[i]] - 1] = array[i];
	countArray[array[i]] -= 1;
}

for (i = 0; i < size; i++)
{
	array[i] = final_Array[i];
}

/* Free allocated memory */
free(countArray);
free(final_Array);
}
