#include "simple_shell.h"

/**
 * cmd_pathfinder - Get the cmd path from environment
 * @cmd: the cmd
 *
 * Return: path to the cmd, NULL if not found
 */
char *cmd_pathfinder(char *cmd)
{
	char *path = getenv("PATH");
	struct stat fileState;

	if (!path)
		return (NULL);

	while (path && *path)
	{
		char *file_path;
		size_t token_len = strcspn(path, ":");
		size_t cmd_len = _strlen(cmd);

		if (token_len == 0)
			file_path = strdup(cmd);
		else
		{
			file_path = malloc(token_len + cmd_len + 2);
			if (!file_path)
				return (NULL);

			strncpy(file_path, path, token_len);
			file_path[token_len] = '/';
			strncpy(file_path + token_len + 1, cmd, cmd_len + 1);
		}

		if (stat(file_path, &fileState) == 0)
			return (file_path);

		free(file_path);
		path += token_len;
		path += (*path == ':') ? 1 : 0;
	}

	if (stat(cmd, &fileState) == 0)
		return (strdup(cmd));

	return (NULL);
}
