#include "shell.h"

/**
  *save_history - writes and saves inputs to a history file
  *@input: input
  *Return: 0 (success), -1 (failure)
  */
int save_history(char *input)
{
	int len = 0;
	ssize_t mn, x;
	char *filename = ".shell_history";

	if (!filename)
		return (-1);
	mn = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (mn < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		x = write(mn, input, len);
		if (x < 0)
			return (-1);
	}
	return (1);
}

