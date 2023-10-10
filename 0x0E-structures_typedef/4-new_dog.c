#include "dog.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len = 0;

	for (; str && str[len]; len++)
		;

	dup = malloc(len + 1);
	if (!dup)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}

/**
 * new_dog - Creates a new dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - a pointer to the new dog_t.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *doggo;

	doggo = malloc(sizeof(dog_t));
	if (!doggo)
		return (NULL);

	doggo->name = _strdup(name);
	if (!(doggo->name))
	{
		free(doggo);
		return (NULL);
	}

	doggo->owner = _strdup(owner);
	if (!(doggo->owner))
	{
		free(doggo->name);
		free(doggo);
		return (NULL);
	}

	doggo->age = age;

	return (doggo);
}
