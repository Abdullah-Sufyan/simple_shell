#include "simple_shell.h"

int submain1(void)
{
	char command[MAX_CMD_LENGTH];
	char *newline;
	pid_t pid;
	char *envp[MAX_EN_VAR] = {NULL};

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

		if (newline == NULL)
		{
			continue;
		}

		pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		else if (pid == 0)
		{
			char *args[2];
			args[0] = newline;
			args[1] = NULL;
			envp[100] = NULL;

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
