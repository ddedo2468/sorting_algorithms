#include "sort.h"

/**
 * selection_sort - sorting an array using selction sort algo
 * @arry: unsorted array to work with
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap(array + i, min);
			print_array(array, size);
		}
	}
}
