#include "simple_shell.h"

/**
 * _getf - function that modifies getf function
 *
 * @inputString: argument 1
 * @maxSize: argument 2
 * @inputStream: argument 3
 *
 * Return: Success (0)
 */

char *_getf(char *inputString, int maxSize, FILE *inputStream)
{
	int character;
	int index = 0;

	if (inputString == NULL || maxSize <= 0 || inputStream == NULL)
	{
		return (NULL);
	}


	while (index < maxSize - 1)
	{
		character = fgetc(inputStream);
		if (character == EOF)
		{
			break;
		}

		inputString[index] = (char)character;

		if (inputString[index] == '\n')
		{
			index++;
			break;
		}

		index++;
	}

	inputString[index] = '\0';

	if (index == 0 && character == EOF)
	{
		return (NULL);
	}

	return (inputString);
}
