#include "sort.h"
/**
 * selection_sort - Function of the selection sort algorithm.
 * @array : Pointer to array of integers.
 * @size : Size of array.
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, index_min;
	int tmp, min;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i;
		min = array[i];
		index_min = i;
		while (j < size)
		{
			if (array[j] < min)
			{
				min = array[j];
				index_min = j;
			}
			j++;
		}
		if (i != index_min)
		{
			tmp = array[i];
			array[i] = min;
			array[index_min] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
