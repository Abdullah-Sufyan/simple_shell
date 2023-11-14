#include "simple_shell.h"

/**
 * _setenv - Set new environment variables
 * @argv: Double pointer to commands
 *
 * Return: 0 (Success) or -1 (Failure)
 */
int _setenv(char **argv)
{
	char *name = argv[1], *value = argv[2];

	if (!name || !value || _strlen(name) == 0 || _strchr(name, '='))
		return (-1);

	return (setenv(name, value, 1));
}

/**
 * _unsetenv - Unset environment variables
 * @name: Pointer to the name
 *
 * Return: 0 (Success) or -1 (Failure)
 */
int _unsetenv(char *name)
{
	if (!name)
		return (-1);

	return (unsetenv(name));
}

/**
 * _env - Print all environment variables
 * @env: Pointer to the environment variables
 *
 * Return: Nothing
 */
void _env(char **env)
{
	int i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
