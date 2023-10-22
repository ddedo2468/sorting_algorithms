#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in the array
*/

void bubble_sort(int *array, size_t size)
{
size_t i;
size_t j;
int tmp;
for (i = 0; i < size; i++)
{
for (j = 0; j < size - 1; j++)
{
if (array[j] > array[j + 1])
{
tmp = array[j];
array[j] = array[j + 1];
array[j + 1] = tmp;
print_array(array, size);
}
}
}
}
