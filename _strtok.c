#include "simple_shell.h"

/**
 * _strtok - Breaks string into a sequence of tokens
 * @inputString: String to be split into tokens
 * @delimiter: String containing delimiter characters
 * @pointer: Pointer to the current position in the string
 *
 * Return: Pointer to the next token found in the string,
 * or NULL if no more tokens are found
 */

char *_strtok(char *inputString, const char *delimiter, char **pointer)
{
	if (inputString != NULL)
		*pointer = inputString;
	else
		inputString = *pointer;

	/*Skip leading delimiters*/
	while (*inputString && strchr(delimiter, *inputString))
		inputString++;

	if (*inputString == '\0')
		return (NULL);

	/*Find the end of the token*/
	char *token = inputString;

	while (*inputString && !strchr(delimiter, *inputString))
		inputString++;

	if (*inputString)
		*inputString++ = '\0';

	*pointer = inputString;
	return (token);
}
