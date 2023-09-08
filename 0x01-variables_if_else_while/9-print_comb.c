#include <stdio.h>

/**
 * main - prints all possible combinations of single-digit numbers
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	/* Loop from 0 to 9 */
	for (i = 0; i < 10; i++)
	{
		putchar(i + '0'); /* Convert integer to character representation */
		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
