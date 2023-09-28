#include "main.h"

int check_prime(int n, int i);

/**
 * is_prime_number - checks if a number is prime.
 * @n: number to check
 * Return: 1 if n is prime, otherwise 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (check_prime(n, 2));
}

/**
 * check_prime - if a num is divisible by any number up to its square root.
 * @n: number to check
 * @i: current divisor
 * Return: 1 if n is prime, otherwise 0
 */
int check_prime(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (check_prime(n, i + 1));
}
