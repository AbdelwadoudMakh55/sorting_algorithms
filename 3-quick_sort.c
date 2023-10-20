#include "sort.h"
/**
 * check_max - Find the max of a list.
 * @array : Array of integers.
 * @size : Size of the array.
 * Return: max (int).
 */
int check_max(int *array, size_t size)
{
	unsigned int i = 0;
	int max = array[0];

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}
/**
 * quick_sort - Function of the algorithm of quick sort.
 * @array : Pointer to array of integers.
 * @size : Size of the array.
 * Return: Void.
 */
void quick_sort(int *array, size_t size)
{
	unsigned int low = 0, high = size - 2, i = 0, copy_size = size;
	int pivot, tmp;

	while (i < copy_size)
	{
		pivot = array[copy_size - 1];
		if (pivot == check_max(array, copy_size))
		{
			copy_size--;
			pivot = array[copy_size - 1];
		}
		high = copy_size - 2;
		low = 0;
		while (high > low)
		{
			while (array[low] < pivot && high > low)
				low++;
			while (array[high] > pivot && high > low)
				high--;
			if (array[low] > pivot && array[high] < pivot && high > low)
			{
				tmp = array[low];
				array[low] = array[high];
				array[high] = tmp;
				print_array(array, size);
				high--;
				low++;
			}
		}
		if (pivot < array[low])
		{
			tmp = array[low];
			array[low] = pivot;
			pivot = tmp;
			array[copy_size - 1] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
