#include <stdio.h>

/**
 * main - prints all possible combinations of two two-digit numbers
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	/* Loop for the first two-digit number */
	for (i = 0; i < 100; i++)
	{
		/* Loop for the second two-digit number */
		for (j = 0; j < 100; j++)
		{
			/* Ensure the combination is unique */
			if (i < j)
			{
				/* Print the first number */
				putchar((i / 10) + '0');
				putchar((i % 10) + '0');
				putchar(' ');

				/* Print the second number */
				putchar((j / 10) + '0');
				putchar((j % 10) + '0');

				/* Don't add comma and space after the last combination */
				if (i != 98 || j != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
