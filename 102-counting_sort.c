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
/* Find the maximum value in the array */
int max_value;
int *countArray;
int j;
int output_index;
size_t i;

max_value = array[0];
for (i = 1; i < size; i++)
{
if (array[i] > max_value)
{
max_value = array[i];
}
}

/* Allocate and initialize the countArray */
countArray = (int *)malloc((max_value + 1) * sizeof(int));
if (countArray == NULL)
{
return;
}

for (j = 0; j <= max_value; j++)
{
countArray[j] = 0;
}
/* Count occurrences of each element */
for (i = 0; i < size; i++)
{
countArray[array[i]]++;
}
/* Print countArray */
print_array(countArray, max_value);

/* Place elements in sorted order */
output_index = 0;
for (j = 0; j <= max_value; j++)
{
while (countArray[j] > 0)
{
array[output_index] = j;
output_index++;
countArray[j]--;
}
}
/* Free allocated memory */
free(countArray);
}
