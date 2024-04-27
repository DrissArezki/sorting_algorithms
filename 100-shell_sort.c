#include "sort.h"

/**
 * max_diff - calculating the gap
 * @size: size of the array
 *
 * return: size_t element
 */
size_t max_diff(size_t size)
{
	size_t x;

	x = 1;
	while (x < size)
		x = x * 3 - 1;
	return ((x - 1) / 3);
}

/**
 * shell_sort - sorting using the shell algo
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t diff, i, j;
	int temp;

	if (!array || !size)
		return;

	for (diff = max_diff(size); diff; diff = (diff - 1) / 3)
	{
		for (i = diff; i < size; i++)
		{
			temp = array[i];
			for (j = i; j > diff - 1 && array[j - diff] > temp; j -= diff)
			{
				array[j] = array[j - diff];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
