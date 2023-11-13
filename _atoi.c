#include "simple_header.h"

int cust_atoi(const char *str)
{
	int result = 0, sign = 1;

	while (cust_isspace(*str)) str++;
	if (*str == '-') { sign = -1; str++; }
	else if (*str == '+') str++;

	while (cust_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return (result * sign);
}
