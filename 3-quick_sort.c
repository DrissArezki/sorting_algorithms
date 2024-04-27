#include "sort.h"

/**
 * swap_func - function that swaps two ints
 * @array: array with elmts
 * @size: size of array
 * @a: int one
 * @b: int two
 *
 * Return: void
 */
void swap_func(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_part - partition using the pivot
 * @array: array to use
 * @size: size of the array
 * @min: min index of the range
 * @max: max index
 *
 * Return: size_t
 */
size_t lomuto_part(int *array, size_t size, ssize_t min, ssize_t max)
{
	int i, j, piv = array[max];

	for (i = j = min; j < max; j++)
		if (array[j] < piv)
			swap_func(array, size, &array[j], &array[i++]);
	swap_func(array, size, &array[i], &array[max]);

	return (i);
}

/**
 * quicks - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 * @min: minimum index
 * @max: maximum index
 *
 * Return: void
 */
void quicks(int *array, size_t size, ssize_t min, ssize_t max)
{
	if (min < max)
	{
		size_t p = lomuto_part(array, size, min, max);

		quicks(array, size, min, p - 1);
		quicks(array, size, p + 1, max);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quicks(array, size, 0, size - 1);
}
