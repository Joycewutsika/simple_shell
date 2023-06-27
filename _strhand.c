#include "shell.h"

/**
  *_putchar - writes character to stdout
  *@c: character
  *Return: character to stdout
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  *_puts - prints a string
  *@str: pointer
  *Return: void
  */
void _puts(char *str)
{
	int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		_putchar(str[x]);
	}
	_putchar('\n');
}

/**
  *_strlen - counts the length of a string
  *s: string input
  *Return: length
  */
int _strlen(char *s)
{
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{
		continue;
	}
	return (x);
}

/**
  *_strncpy - copies a string
  *@dest: destination string
  *@src: source string
  *@n: number of characters
  *Return: copied string
  */
char *_strncpy(char *dest, char *src, int n)
{
	int x = 0;

	while (x < n && *(src + x))
	{
		*(dest + x) = *(src + x);
		x++;
	}
	while (x < n)
	{
		*(dest + x) = '\0';
		x++;
	}
	return (dest);
}

/**
  *_atoi - converts string to an integer
  *@s: string
  *Return: converted integer
  */
int _atoi(char *s)
{
	int x = 0, y = 1, z;
	unsigned int p = 0;

	while (s[x] != '\0')
	{
		if (s[x] == '-')
		{
			return (2);
		}
		z = s[x] - '0';

		if (p > 0 && !(z >= 0 && z <= 9))
			break;

		if (z >= 0 && z <= 9)
			p = p * 10 + z;

		x++;
	}
	p *= y;
	return (p);
}
