#include "shell.h"

/**
  *find_executable - searches for an executable command
  *@cmd: parsed input command
  *Return: 0 (success), i (failure)
  */
int find_executable(char **cmd)
{
	struct stat buf;
	char *path, *mkr, *cmd_path;

	path = get_env_variable("PATH");
	if (path == NULL)
		return (1);

	mkr = strtok(path, ": ");
	while (mkr != NULL)
	{
		cmd_path = build_command_path(*cmd, mkr);
		if (stat(cmd_path, &buf) == 0)
		{
			free(*cmd);
			*cmd = strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		mkr = strtok(NULL, ": ");
	}
	free(path);
	return (1);
}

/**
  *build_command_path - builda the full path of a command
  *@command: command
  *@dir: directory
  *Return: parsed full path of the command or NULL if failed
  */
char *build_command_path(char *command, char *dir)
{
	size_t path_len;
	char *path;

	path_len = _strlen(dir) + _strlen(command) + 2;
	path = malloc(sizeof(char) * path_len);
	if (path == NULL)
	{
		perror("unable to allocate memory");
		return (NULL);
	}

	memset(path, 0, path_len);

	_strcat(path, dir);
	_strcat(path, "/");
	_strcat(path, command);

	return (path);
}

/**
  *get_env_variable - checks the value og variable by name
  *@name: variable name
  *Return: the value of variable or NULL if not found
  */
char *get_env_variable(char *name)
{
	size_t name_len, value_len;
	char *value;
	int x, y;

	name_len = strlen(name);
	for (x = 0; environ[x]; x++)
	{
		if (strncmp(name, environ[x], name_len) == 0 && environ[x][name_len] == '=')
		{
			value_len = _strlen(environ[x]) - name_len - 1;
			value = malloc(sizeof(char) * (value_len + 1));
			if (!value)
			{
				perror("unable to allocate memory");
				return (NULL);
			}

			y = 0;
			while (environ[x][name_len + 1 + y] != '\0')
			{
				value[y] = environ[x][name_len + 1 + y];
				y++;
			}
			value[y] = '\0';

			return (value);
		}
	}
	return (NULL);
}
