#include "sort.h"
/**
* selection_sort - sorts an array of integers in ascending
* order using the Selection sort algorithm
* @array: array of integers
* @size: size of the array
* Return: nothing.
**/

void selection_sort(int *array, size_t size)
{
	int i, j, min, temp;
	int new_size = size;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < (new_size - 1); i++)
	{
		min = i;
		for (j = i + 1; j < new_size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min == i)
			continue;

		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		print_array(array, size);
	}
}
