#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @a: pointer to first element
 * @b: pointer to second element
 */
void swap(int *a, int *b)
{
    if (*a != *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

/**
 * lomuto_partition - Partition using Lomuto scheme
 * @array: the array to sort
 * @low: starting index
 * @high: ending index
 * @size: total size of the array (used for printing)
 * Return: index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }
    }
    if (i != high)
    {
        swap(&array[i], &array[high]);
        print_array(array, size);
    }
    return (i);
}

/**
 * quick_sort_recursive - Recursive function to apply quicksort
 * @array: the array to sort
 * @low: starting index
 * @high: ending index
 * @size: total size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array using Quick Sort algorithm
 * @array: the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
