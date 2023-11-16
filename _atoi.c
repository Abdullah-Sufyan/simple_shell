#include "simple_shell.h"

/**
 * _atoi - Convert a string to an integer.
 * @inputString: The string containing the numeric characters.
 *
 * Return: The converted integer value.
 */

int _atoi(const char *inputString)
{
	int result = 0, sign = 1;

	while (_isspace(*inputString))
		inputString++;
	if (*inputString == '-')
	{
		sign = -1;
		inputString++;
	}
	else if (*inputString == '+')
		inputString++;

	while (_isdigit(*inputString))
	{
		result = result * 10 + (*inputString - '0');
		inputString++;
	}

	return (result * sign);
}
