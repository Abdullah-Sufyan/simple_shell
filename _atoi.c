#include "simple_shell.h"

int _atoi(const char *inputString)
{
	int result = 0, sign = 1;

	while (_isspace(*inputString)) inputString++;
	if (*inputString == '-') { sign = -1; inputString++; }
	else if (*inputString == '+') inputString++;

	while (_isdigit(*inputString))
	{
		result = result * 10 + (*inputString - '0');
		inputString++;
	}

	return (result * sign);
}
