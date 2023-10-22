#include "sort.h"

int partition(int *array, size_t size, int left, int right);
void recursive_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap - swaping 2 elements of an array
 * @a: an element to swap with b
 * @b: an element to swap with a
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - ordering a subset of an array.
 * @array: an array of ints.
 * @size: array size.
 * @left: array first element.
 * @right: array last element.
 * Return: The pivot position.
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, i, j;

	pivot = array + right;
	for (i = j = left; j < right; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * recursive_sort - Implement the quicksort algorithm through recursion.
 * @array: an array of ints.
 * @size: array size.
 * @left: array first element.
 * @right: array last element.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void recursive_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		recursive_sort(array, size, left, part - 1);
		recursive_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_sort(array, size, 0, size - 1);
}
