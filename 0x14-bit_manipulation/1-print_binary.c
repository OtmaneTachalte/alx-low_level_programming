#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(n) * 8 - 1);

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (!(mask & n))
		mask >>= 1;

	while (mask)
	{
		if (n & mask)
			_putchar('1');
		else
			_putchar('0');

		mask >>= 1;
	}
}
