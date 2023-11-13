#include "simple_shell.h"

int _atoi(const char *str)
{
	int result = 0, sign = 1;

	while (_isspace(*str)) str++;
	if (*str == '-') { sign = -1; str++; }
	else if (*str == '+') str++;

	while (_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return (result * sign);
}
