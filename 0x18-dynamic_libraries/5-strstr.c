#include "main.h"

/**
 * _strstr - Locates a substring.
 * @haystack: The main string to be searched.
 * @needle: The substring to be located.
 *
 * Return: A pointer to the beginning of the located substring,
 *         or 0 if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j;

	if (!*needle)
	{
		return (haystack);
	}

	for (i = 0; haystack[i]; i++)
	{
		for (j = 0; needle[j]; j++)
		{
			if (haystack[i + j] != needle[j])
			{
				break;
			}
		}
		if (!needle[j])
		{
			return (haystack + i);
		}
	}

	return (0);
}
