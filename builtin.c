#include "custom_shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char input[MAX_CMD_LENGTH];

	while (1)
	{
		_printf(); /* Print custom shell prompt */
		fflush(stdout);

		if (*_getf(input, MAX_CMD_LENGTH, stdin) == NULL)
			/* Handle end of file condition (Ctrl+D) */
			_printf("\nExiting simple shell...\n");
		break;
	}

	char *newline = strtok(command, "\n");

	if (newline == NULL)
	{
		continue;
	}

	if (_strcmp(newline, "env") == 0)
	{
		/* User entered "env" - print environment */
		char **env = environ();

		while (*env != NULL)
		{
			_printf(*env);
			env++;
		}
		continue;
	}

	if (_strcmp(newline, "exit") == 0)
	{
		/* User entered "exit" - exit the shell */
		break;
	}

	pid_t pid = fork();

	if (pid < 0)
	{
		/* Forking error */
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* In the child process */
		/* Execute the command using execve */
		char *args[] = {newline, NULL};

		if (execve(newline, args, NULL) == -1)
		{
			/* Command not found or failed to execute */
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* In the parent process */
		int status;
		/* Wait for the child process to finish */
		waitpid(pid, &status, 0);
	}
}
return (0);
}
