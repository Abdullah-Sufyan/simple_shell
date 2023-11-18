#include "simple_shell.h"

/**
 * _strlen - Calculates the length of a string
 * @inputString: Input string
 *
 * Return: Length of the string
 */

int _strlen(const char *inputString)
{
	int length = 0;

	while (inputString[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @inputString: Input string
 * @character: Character to be found
 *
 * Return: Pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found
 */

char *_strchr(const char *inputString, char character)
{
	while (*inputString != '\0')
	{
		if (*inputString == character)
		{
			return ((char *)inputString);
		}
		inputString++;
	}
	return (NULL);
}
