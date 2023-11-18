#include "simple_shell.h"

/**
 * _strcmp - Compares two strings
 * @stringA: First string
 * @stringB: Second string
 *
 * Return: 0 if strings are equal, otherwise difference between ASCII values
 */

int _strcmp(const char *stringA, const char *stringB)
{
	while (*stringA == *stringB)
	{
		if (*stringA == '\0')
			return (0);

		stringA++;
		stringB++;
	}

	return (*stringA - *stringB);
}
