#include "sort.h"

/**
 * swap_selection - function to swap the position of two elements
 * @a: ptr to take an int
 * @b: ptr to take an int
 */
void swap_selection(int *a, int *b)
{
	int current;

	current = *a;
	*a = *b;
	*b = current;
}

/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: ptr to array of the int
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int *current;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		current = &array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *current)
			{
				current = &array[j];
			}
		}
		if (current != &array[i])
		{
			swap_selection(current, &array[i]);
			print_array(array, size);
		}
	}
}
