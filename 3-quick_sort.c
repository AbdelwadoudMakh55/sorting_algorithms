#include "sort.h"
/**
 * partition - Function of the partition.
 * @l : Lowest point of array.
 * @h : Highest point of array.
 * @array : Pointer to array of integers.
 * @size : Size of the array.
 * Return: Position of pivot.
 */
int partition(int l, int h, int *array, size_t size)
{
	int pivot = array[h], i = l - 1, tmp, j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[h];
	array[h] = tmp;
	print_array(array, size);
	return (i + 1);
}
/**
* quick_sort - Function of the algorithm of quick sort.
* @array : Pointer to array of integers.
* @size : Size of the array.
* Return: Void.
*/
void quick_sort(int *array, size_t size)
{
	int pivot;

	if (size > 1)
	{
		pivot = partition(0, size - 1, array, size);
		print_array(array, size);
		quick_sort(array, pivot);
		quick_sort(array + pivot + 1, size - pivot - 1);
	}
}
