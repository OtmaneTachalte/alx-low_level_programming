#include <stdio.h>

/**
 * main - Prints numbers between 0 to 9 and letters between a to f.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	/* Loop from '0' ASCII (48) to '9' ASCII (57) */
	for (i = 48; i < 58; i++)
	{
		putchar(i);
	}

	/* Loop from 'a' ASCII (97) to 'f' ASCII (102) */
	for (i = 97; i < 103; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
