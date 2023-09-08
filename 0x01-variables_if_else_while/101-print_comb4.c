#include <stdio.h>

/**
 * main - prints all possible different combinations of three digits
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j, k;

	/* Loop for the first digit */
	for (i = 0; i <= 9; i++)
	{
		/* Loop for the second digit */
		for (j = i + 1; j <= 9; j++)
		{
			/* Loop for the third digit */
			for (k = j + 1; k <= 9; k++)
			{
				putchar(i + '0'); /* Convert integer to character representation */
				putchar(j + '0'); /* Convert integer to character representation */
				putchar(k + '0'); /* Convert integer to character representation */

				/* Don't add comma and space after the last combination */
				if (i != 7 || j != 8 || k != 9)
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
