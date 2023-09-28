#include "main.h"

int find_sqrt(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: number to find its square root
 * Return: natural square root or -1 if n doesn't have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (find_sqrt(n, 0));
}

/**
 * find_sqrt - finds the square root of a number.
 * @n: target number
 * @i: number to check
 * Return: square root or -1 if not found
 */
int find_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (find_sqrt(n, i + 1));
}
