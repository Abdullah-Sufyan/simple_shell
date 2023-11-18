#include "simple_shell.h"

/**
 * execute_cmd - Execute a command.
 * @arguments: Double pointer to command arguments.
 *
 * Return: Exit status of the command.
 */
int execute_cmd(char **arguments)
{
	int do_id = fork();
	int quit_status = 0;

	if (do_id == 0)
	{
		if (execve(arguments[0], arguments, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&quit_status);
		if (WIFEXITED(quit_status))
			quit_status = WEXITSTATUS(quit_status);
	}

	return (quit_status);
}
