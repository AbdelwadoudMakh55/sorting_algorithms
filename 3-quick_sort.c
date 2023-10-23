#include "sort.h"
/**
 * partition - Function of the partition.
 * @l : Lowest point of array.
 * @h : Highest point of array.
 * @array : Pointer to array of integers.
 * @copy_array : A copy of the array.
 * @copy_size : Copy of size of array.
 * Return: Position of pivot.
 */
int partition(int l, int h, int *array, int *copy_array, int copy_size)
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
			if (i != j)
				print_array(copy_array, copy_size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[h];
	array[h] = tmp;
	if (i + 1 != h)
		print_array(copy_array, copy_size);
	return (i + 1);
}
/**
* quick_sort - Function of the algorithm of quick sort.
* @array : Pointer to array of integers.
* @l : Low index.
* @h : High index.
* @size : Size of the array.
* @copy_array : A copy of the array.
* @copy_size : Copy of size of array.
* Return: Void.
*/
void quick_sort_recursive(int *array, int l, int h, size_t size,
int *copy_array, size_t copy_size)
{
	int pivot;

	if (l < h)
	{
		pivot = partition(l, h, array, copy_array, copy_size);
		quick_sort_recursive(array, l, pivot - 1, size, copy_array, copy_size);
		quick_sort_recursive(array, pivot + 1, h, size, copy_array, copy_size);
	}
}
void quick_sort(int *array, size_t size)
{
	int *copy_array = array;
	size_t copy_size = size;

	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(copy_array, 0, size - 1, size, copy_array, copy_size);
}
