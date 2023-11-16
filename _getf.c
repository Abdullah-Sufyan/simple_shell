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
	int c;
	int index = 0;

	if (inputString == NULL || maxSize <= 0 || inputStream == NULL)
	{
		return (NULL);
	}


	while (index < maxSize - 1)
	{
		c = fgetc(inputStream);
		if (c == EOF)
		{
			break;
		}

		inputString[index] = (char)c;

		if (inputString[index] == '\n')
		{
			index++;
			break;
		}

		index++;
	}

	inputString[index] = '\0';

	if (index == 0 && c == EOF)
	{
		return (NULL);
	}

	return (inputString);
}
