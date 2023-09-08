#include <stdio.h>

/**
 * main - prints the lowercase alphabet in reverse,
 * followed by a new line.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;

	/* Loop from 'z' to 'a' */
	for (ch = 'z'; ch >= 'a'; ch--)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
