#include "simple_shell.h"
/**
 * _isdigit - Checks if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */

int _isdigit(char c)
{
	/* Returns 1 if 'c' is between '0' and '9', 0 otherwise */
	return (c >= '0' && c <= '9');
}
