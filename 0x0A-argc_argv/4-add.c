#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 if any of the numbers contain non-digit symbols
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	for (i = 1; i < argc; i++)
	{
		char *s = argv[i];

		while (*s)
		{
			if (*s < '0' || *s > '9')
			{
				printf("Error\n");
				return (1);
			}
			s++;
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}

