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
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * counting_sort - Sorts the array based on a specific significant digit using Counting Sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The exponent of the specific significant digit.
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    if (output == NULL)
    {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    /* Count occurrences of digits */
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Modify count[i] so that count[i] now contains the actual position of this digit in output */
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the output array back to the original array */
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    /* Print array after sorting on this significant digit */
    print_array(array, size);

    /* Free the temporary memory used for output */
    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int max = find_max(array, size);

    /* Perform counting sort for every digit */
    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort_radix(array, size, exp);
}
