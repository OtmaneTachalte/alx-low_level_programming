#include "main.h"

/**
 * factorial - returns the factorial of a given number.
 * @n: number to calculate its factorial
 * Return: factorial of the number
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
