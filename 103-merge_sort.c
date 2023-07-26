#include "sort.h"

/* Function to merge two sorted sub-arrays into one sorted array */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size) {
    size_t i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }

    /* Free temporary memory used for left and right arrays */
    free(left);
    free(right);
}

/* Recursive function for Merge sort */
void merge_sort_recursive(int *array, size_t size) {
    if (size <= 1)
        return;

    size_t mid = size / 2;

    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((size - mid) * sizeof(int));

    for (size_t i = 0; i < mid; i++)
        left[i] = array[i];

    for (size_t i = mid; i < size; i++)
        right[i - mid] = array[i];

    merge_sort_recursive(left, mid);
    merge_sort_recursive(right, size - mid);

    merge(array, left, mid, right, size - mid);
}

/* Wrapper function for merge_sort */
void merge_sort(int *array, size_t size) {
    if (array == NULL || size <= 1)
        return;

    merge_sort_recursive(array, size);
}
