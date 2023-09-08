#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Prints the alphabet without q and e.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	/* Loop from 'a' ASCII (97) to 'z' ASCII (122) */
	for (i = 97; i < 123; i++)
	{
		/* Skip characters 'e' and 'q' */
		if (i != 101 && i != 113)
		{
			putchar(i);
		}
	}
	putchar('\n');
	return (0);
}
