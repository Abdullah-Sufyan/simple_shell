#include "simple_shell.h"

/**
 * _strdup - Duplicates a string.
 * @inputString: The string to be duplicated.
 *
 * Return: Pointer to the duplicated string or NULL if str is NULL
 * or if memory allocation fails.
 */
char *_strdup(const char *inputString)
{
	size_t len = 0;

	char *duplicate;

	size_t i;

	if (inputString == NULL)
		return (NULL);


	while (inputString[len] != '\0')
		len++;

	duplicate = malloc((len + 1) * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		duplicate[i] = inputString[i];

	return (duplicate);
}
