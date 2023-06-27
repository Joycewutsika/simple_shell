#include "shell.h"

/**
  *_strtok - extracts tokens from a string.
  *@str: string
  *@delim: delimeter characters
  *Return: pointer to the next token
  */
char *_strtok(char *str, const char *delim)
{
	unsigned int x;
	static char *tokens;
	static char *next_token;

	if (str != NULL)
		next_token = str;
	tokens = next_token;
	if (tokens == NULL)
		return (NULL);
	for (x = 0; tokens[x] != '\0'; x++)
	{
		if (!is_char_match(tokens[x], delim))
			break;
	}
	if (next_token[x] == '\0' || next_token[x] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	tokens = next_token + x;
	next_token = tokens;
	for (x = 0; next_token[x] != '\0'; x++)
	{
		if (is_char_match(next_token[x], delim))
			break;
	}
	if (next_token[x] == '\0')
		next_token = NULL;
	else
	{
		next_token[x] = '\0';
		next_token = next_token + x + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (tokens);
}

/**
  *is_char_match - checks if a character matches any character.
  *@ch: character to check.
  *@str: string of characters.
  *Return: 1 (success), 0 (failure)
  */
unsigned int is_char_match(char ch, const char *str)
{
	unsigned int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		if (ch == str[x])
			return (1);
	}
	return (0);
}
