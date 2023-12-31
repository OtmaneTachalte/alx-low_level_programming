#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that generates random valid
 * passwords for the program 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int pass[100];
	int i, sum, n;

	sum = 0;

	/* Seed the random number generator */
	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		/* Generate a random character */
		pass[i] = rand() % 78;
		sum += (pass[i] + '0');
		putchar(pass[i] + '0');

		/* Check if the remaining sum can be achieved with a single character */
		if ((2772 - sum) - '0' < 78)
		{
			n = 2772 - sum - '0';
			sum += n;
			putchar(n + '0');
			break;
		}
	}

	putchar('\n');

	return (0);
}
