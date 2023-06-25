#include "shell.h"

/**
 *separateCommand - It separates command
 *@input: The string
 *
 *Return: strings to be used
 */
char **separateCommand(char *input)
{
	char **cmds;
	char *cmd;
	int x;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	cmds = malloc(sizeof(char *) * buffsize);
	if (!cmds)
	{
		free(cmds);
		perror("hsh");
		return (NULL);
	}
	cmd = _strtok(input, ";&");
	for (x = 0; cmd; x++)
	{
		cmds[x] = cmd;
		cmd = _strtok(NULL, ";&");
	}

	cmds[x] = NULL;

	return (cmds);
}
