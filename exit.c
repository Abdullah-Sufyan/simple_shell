#include "simple_shell.h"

/**
 * executeCommand - Forks and executes a given command
 * @command: Command to be executed
 */
void executeCommand(char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("FORK FAILED");
		exit(1);
	}
	else if (pid == 0)
	{
		char *args[2];

		args[0] = command;

		args[1] = NULL;

		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

	}
}

/**
 * handleUserInput - Handles user input and executes commands
 */
void handleUserInput(void)
{
	char command[MAX_CMD_LENGTH];
	char *newline;

	while (1)
	{
		_printf("simple_shell$ ");
		fflush(stdout);

		if (_getf(command, MAX_CMD_LENGTH, stdin) == NULL)
		{
			_printf("\nExiting simple shell...\n");
			break;
		}

		newline = strtok(command, "\n");

		if (newline == NULL || _strcmp(newline, "exit") == 0)
		{
			break;
		}

		executeCommand(newline);
	}
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	handleUserInput();
	return (0);
}
