#include "sort.h"
/**
 * max_array - Find the maximum number of an array.
 * @array : Array of integers.
 * @size : Length of array.
 * Return: Max of the array.
 */
int max_array(int *array, size_t size)
{
	size_t i = 0;
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
 * counting_sort - The algorithm of counting sort.
 * @array : array to be sorted.
 * @size : Length of array.
 * Return: Void.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *copy_array, key, j, SIZE = size, index, index1;
	size_t i;

	if (size == 1 || array == NULL)
		return;
	key = max_array(array, size) + 1;
	count_array = malloc(sizeof(int) * key);
	copy_array = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		copy_array[i] = array[i];
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (j = 1; j < key; j++)
	{
		count_array[j] += count_array[j - 1];
	}
	print_array(count_array, key);
	for (j = SIZE - 1; j >= 0; j--)
	{
		index = copy_array[j];
		count_array[index] -= 1;
		index1 = count_array[index];
		array[index1] = copy_array[j];
	}
	free(count_array);
	free(copy_array);
}
