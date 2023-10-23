#include "sort.h"
/**
 * knuth_gap - Find the initial value of gap.
 * @size : Size of array.
 * Return: gap value.
 */
int knuth_gap(size_t size)
{
	size_t gap = 1;
	int GAP;

	while (gap < size)
		gap = gap * 3 + 1;
	GAP = ((gap - 1) / 3);
	return (GAP);
}
/**
 * shell_sort - Algorithm of shell sort.
 * @array : Array to be sorted.
 * @size : Length of array.
 * Return: Void.
 */
void shell_sort(int *array, size_t size)
{
	int gap = knuth_gap(size), tmp, i, SIZE = size;

	while (gap >= 1)
	{
		for (i = 0; gap + i < SIZE; i++)
		{
			if (array[i] >= array[gap + i])
			{
				tmp = array[i];
				array[i] = array[gap + i];
				array[gap + i] = tmp;
				while (gap <= i && array[i - gap] >= array[i])
				{
					tmp = array[i];
					array[i] = array[i - gap];
					array[i - gap] = tmp;
					i--;
				}
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
