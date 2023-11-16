#include "simple_shell.h"

/**
 * _isspace - function to customize isspace
 * @c: character
 *
 * Return: 0 on success
 */
int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r');
}
