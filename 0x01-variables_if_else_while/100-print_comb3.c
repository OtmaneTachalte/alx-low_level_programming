#include <stdio.h>

/**
 * main - prints all possible different combinations of two digits
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	/* Loop for the first digit */
	for (i = 0; i <= 8; i++)
	{
		/* Loop for the second digit */
		for (j = 1; j <= 9; j++)
		{
			if (j > i)
			{
				putchar(i + '0'); /* Convert integer to character representation */
				putchar(j + '0'); /* Convert integer to character representation */
				if (i != 8 || j != 9)
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
