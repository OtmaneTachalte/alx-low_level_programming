#include <stdlib.h>
#include "main.h"

/**
 * word_count - counts the number of words in a string
 * @str: string to evaluate
 *
 * Return: number of words
 */
int word_count(char *str)
{
	int flag, i, words;

	flag = 0;
	words = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			words++;
		}
	}

	return (words);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words, *word;
	int i, k = 0, len = 0, wc, c = 0, start, end;

	while (*(str + len))
		len++;
	wc = word_count(str);
	if (wc == 0)
		return (NULL);

	words = (char **) malloc(sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				word = (char *) malloc(sizeof(char) * (c + 1));
				if (word == NULL)
					return (NULL);
				while (start < end)
					*word++ = str[start++];
				*word = '\0';
				words[k] = word - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	words[k] = NULL;

	return (words);
}
