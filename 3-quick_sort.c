#include "sort.h"

/**
 * swap_q - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_q(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Perform Lomuto partition scheme
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_q(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap_q(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursive - Recursive function to sort an array using quicksort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, pivot_idx - 1, size);
		quicksort_recursive(array, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursive(array, 0, (int)size - 1, size);
}
