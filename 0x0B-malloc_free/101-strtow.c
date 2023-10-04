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
 * create_word - creates a word from the string
 * @str: string starting from the word
 * @start: start index of the word
 * @end: end index of the word
 *
 * Return: pointer to the word
 */
char *create_word(char *str, int start, int end)
{
	char *word;
	int i;

	word = (char *) malloc(sizeof(char) * (end - start + 2));
	if (!word)
		return (NULL);

	for (i = 0; start < end; i++, start++)
		word[i] = str[start];
	word[i] = '\0';

	return (word);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, k = 0, len = 0, wc, c = 0, start, j;

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
				words[k] = create_word(str, start, i);
				if (!words[k])
				{
					for (j = 0; j < k; j++)
						free(words[j]);
					free(words);
					return (NULL);
				}
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
