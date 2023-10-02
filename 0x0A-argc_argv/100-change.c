#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make change
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 if the number of arguments is not 1
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	/* Quarters */
	coins += cents / 25;
	cents %= 25;

	/* Dimes */
	coins += cents / 10;
	cents %= 10;

	/* Nickels */
	coins += cents / 5;
	cents %= 5;

	/* Two pennies */
	coins += cents / 2;
	cents %= 2;

	/* Pennies */
	coins += cents;

	printf("%d\n", coins);

	return (0);
}
