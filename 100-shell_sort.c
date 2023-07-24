#include "sort.h"

/**
 * shell_sort - Sorts an array of ints in
 * ascending order using the Shell sort algo
 * @array: Pointer to the array to sort
 * @size: The size of the array
 */

void shell_sort(int *array, size_t size)
{
size_t interval;
int valueToInsert;
size_t inner;
size_t outer;
interval = 1;
while (interval <= size / 3)
	interval = interval * 3 + 1;

while (interval > 0)
{
for (outer = interval; outer < size; outer++)
{
valueToInsert = array[outer];
inner = outer;
while (inner > interval - 1 && array[inner - interval] >= valueToInsert)
{
array[inner] = array[inner - interval];
inner = inner - interval;
}
array[inner] = valueToInsert;
}
print_array(array, size);
interval = (interval - 1) / 3;
}
}
