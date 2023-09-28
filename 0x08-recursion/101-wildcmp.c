#include "main.h"

int compare_strings(char *s1, char *s2);

/**
 * wildcmp - compares two strings considering wildcard *.
 * @s1: first string
 * @s2: second string which might contain wildcard *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	return (compare_strings(s1, s2));
}

/**
 * compare_strings - compares two strings recursively.
 * @s1: first string
 * @s2: second string
 * Return: 1 if the strings are identical, otherwise 0
 */
int compare_strings(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (compare_strings(s1 + 1, s2 + 1));
	if (*s2 == '*')
		return (compare_strings(s1 + 1, s2) || compare_strings(s1, s2 + 1));
	return (0);
}
