#include "sort.h"
/**
 * bubble_sort - the Bubble sort algorithm.
 * @array : Array of integers.
 * @size : Size of the array.
 * Return: Void.
 */
void bubble_sort(int *array, size_t size)
{
	int tmp = 0;
	size_t i, j;

	for (j = 0; j < size - 1; j++)
	{
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
}
