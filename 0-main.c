#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point for testing the bubble_sort function
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    /* Print the original array */
    printf("Original array:\n");
    print_array(array, n);

    /* Sort the array using Bubble Sort */
    printf("\nSorting steps:\n");
    bubble_sort(array, n);

    /* Print the array after sorting */
    printf("\nSorted array:\n");
    print_array(array, n);

    return (0);
}
