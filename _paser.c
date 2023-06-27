#include "shell.h"

/**
  *parse_input - parses the input string into command arguments
  *@input: the inut string
  *Return: array of parsed command arguments.
  */
char **parse_input(char *input)
{
	int x;
	char *arg;
	char **args;
	int bufsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);

	args = malloc(sizeof(char *) * bufsize);
	if (!args)
	{
		free(args);
		perror("custom_shell");
		return (NULL);
	}

	arg = _strtok(input, "\n\t\r\a ");
	for (x = 0; arg; x++)
	{
		args[x] = arg;
		arg = _strtok(NULL, "\n\t\r\a ");
	}
	args[x] = NULL;

	return (args);
}
