#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to the new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str, *ptr;
	int i, j, total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate total length for the new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			total_len++;
		total_len++; /* For the newline */
	}

	/* Allocate memory for the new string */
	str = malloc((total_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	ptr = str;

	/* Populate the new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			*ptr = av[i][j];
			ptr++;
		}
		*ptr = '\n';
		ptr++;
	}

	*ptr = '\0'; /* Null terminate the new string */

	return (str);
}
