#include <stdio.h>

/**
 * main - Prints the alphabet in both lowercase and uppercase.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;

	// Print lowercase alphabet
	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}

	// Print uppercase alphabet
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		putchar(ch);
	}

	putchar('\n');
	return (0);
}
