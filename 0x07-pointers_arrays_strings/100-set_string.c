#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: The pointer to set.
 * @to: The char value to set s to.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
