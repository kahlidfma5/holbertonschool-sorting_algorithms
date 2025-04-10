#include "sort.h"

/**
 * swap - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Lomuto partition scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Array size (for printing)
 * Return: Pivot index after partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j && array[i] != array[j])
				print_array(array, size);
			if (i != j)
				swap(&array[i], &array[j]);
			i++;
		}
	}
	if (i != high && array[i] != array[high])
		print_array(array, size);
	if (i != high)
		swap(&array[i], &array[high]);

	return (i);
}

/**
 * quick_sort_recursive - Recursive quick sort
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Array size
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sort array using Quick Sort algorithm
 * @array: Array to sort
 * @size: Array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
