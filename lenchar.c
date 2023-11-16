#include "simple_shell.h"

int _strlen(const char *inputString)
{
	int length = 0;

	while (inputString[length] != '\0')
	{
		length++;
	}

	return (length);
}


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
