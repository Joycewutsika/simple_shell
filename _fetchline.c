#include "shell.h"

/**
 *custom_getline - reads input from standard input
 *Return: input on buffer
 */
char *custom_getline()
{
	int x, y;
	int buffsize = BUFSIZE;
	char m = 0, *buf, *buffer;

	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (x = 0; m != EOF && m != '\n'; x++)
	{
		fflush(stdin);
		y = read(STDIN_FILENO, &m, 1);
		if (y == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[x] = m;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (x >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[x] = '\0';
	buf = modify_space(buffer);
	free(buffer);
	hashtag_handler(buf);
	return (buf);
}

/**
  *hashtag_handler - removes everything after '#'
  *@buff: input buffer
  *Return: nothing
  */
void hashtag_handler(char *buff)
{
	int x;

	for (x = 0; buff[x] != '\0'; x++)
	{
		if (buff[x] == '#' && buff[x - 1] == ' ' && buff[x + 1] == ' ')
		{
			buff[x] = '\0';
		}
	}
}


/**
  *enter - handles newlibe character input
  *@string: string to be handled
  *Return: the empty string
  */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
  *modify_space - checks input string to remove preceding whitespaces
  *@str: input to be modified
  *Return: the modified string
  */
char *modify_space(char *str)
{
	int x, y = 0;
	char *new_buffer;

	new_buffer = malloc(sizeof(char) * (_strlen(str) + 1));
	if (new_buffer == NULL)
	{
		free(new_buffer);
		return (NULL);
	}
	for (x = 0; str[x] == ' '; x++)
		;
	for (; str[x + 1] != '\0'; x++)
	{
		new_buffer[y] = str[x];
		y++;
	}
	new_buffer[y] = '\0';
	if (new_buffer[0] == '\0' || new_buffer[0] == '#')
	{
		free(new_buffer);
		return ("\0");
	}
	return (new_buffer);
}
