#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers from min to max
 * @min: The starting integer
 * @max: The ending integer
 *
 * Return: Pointer to the newly created array, NULL if it fails or min > max
 */
int *array_range(int min, int max)
{
	int *arr;
	int i, range;

	if (min > max)
		return (NULL);

	range = max - min + 1;
	arr = malloc(sizeof(int) * range);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < range; i++, min++)
		arr[i] = min;

	return (arr);
}
