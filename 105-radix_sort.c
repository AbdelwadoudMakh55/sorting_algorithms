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
 * len_digit - Find the number of digits of a number..
 * @n : Integer.
 * Return: Number of digits of an int.
 */
int len_digit(int n)
{
	int len = 0;

	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	return (len + 1);
}
/**
 * radix_sort - The algorithm for the radix sort.
 * @array : Pointer to array.
 * @size : Length of array.
 * Return: Void.
 */
void radix_sort(int *array, size_t size)
{
	int max, len_max, **bucket, pass = 0, ten_pow = 1, index_bucket;
	size_t i, j, k;

	if (array == NULL || size == 1)
		return;
	max = max_array(array, size);
	len_max = len_digit(max);
	bucket = malloc(sizeof(int *) * 10);
	for (i = 0; i < 10; i++)
		bucket[i] = malloc(sizeof(int) * size);
	while (pass < len_max)
	{
		for (i = 0; i < 10; i++)
			for (j = 0; j < size; j++)
				bucket[i][j] = -1;
		for (i = 0; i < size; i++)
		{
			k = 0;
			index_bucket = (array[i] / ten_pow) % 10;
			while (bucket[index_bucket][k] != -1)
				k++;
			bucket[index_bucket][k] = array[i];
		}
		j = 0;
		i = 0;
		while (j < size && i < 10)
		{
			k = 0;
			while (bucket[i][k] != -1 && k < size)
			{
				array[j] = bucket[i][k];
				k++;
				j++;
			}
			i++;
		}
		pass++;
		ten_pow = ten_pow * 10;
		print_array(array, size);
	}
	for (i = 0; i < 10; i++)
		free(bucket[i]);
	free(bucket);
}
