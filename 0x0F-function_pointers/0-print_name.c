#include "function_pointers.h"

/**
 * print_name - prints a name using a given function
 * @name: name to print
 * @f: function to use for printing
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	{
		f(name);
	}
}
