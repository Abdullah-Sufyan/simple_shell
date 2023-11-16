#include "simple_shell.h"

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		customPrint("simple_shell$ ");
		fflush(stdout);

		if (_getf(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			_printf("\nExiting simple shell...\n");
			break;
		}

		char *newline = strtok(command, "\n");

		if (newline == NULL)
		{
			continue;
		}

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		else if (pid == 0)
		{
			char *args[] = {newline, NULL};
			char *envp[] = {NULL};

			if (execve(newline, args, envp) == -1)
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
	return (0);
}
