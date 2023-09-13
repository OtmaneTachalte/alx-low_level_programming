#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms in the Fibonacci
 *  sequence whose values do not exceed 4,000,000, followed by a new line.
 * Return: Always 0.
 */
int main(void)
{
	unsigned long int n1 = 1, n2 = 2, next = 0, sum_even = 2;

	while (1)
	{
		next = n1 + n2;

		if (next > 4000000)
			break;

		if (next % 2 == 0)
			sum_even += next;

		n1 = n2;
		n2 = next;
	}

	printf("%lu\n", sum_even);

	return (0);
}

