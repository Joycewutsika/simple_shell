#include "shell.h"

/**
  *intlen - duplicate a string
  *@num: integer
  *Return: length of integer
  */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
  *array_rev - reverses an array
  *@arr: array
  *@len: length
  */
void array_rev(char *arr, int len)
{
	int x;
	char tmp;

	for (x = 0; x < (len / 2); x++)
	{
		tmp = arr[x];
		arr[x] = arr[(len - 1) - x];
		arr[(len - 1) - x] = tmp;
	}
}

/**
  *_isalpha - checks for alphabet
  *@c: character
  *Return: 1 (true). 0 (false)
  */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
  *_itoa - convert integer to character
  *@n: integer
  *Return: character pointer
  */
char *_itoa(unsigned int n)
{
	char *y;
	int len = 0, x = 0;

	len = intlen(n);
	y = malloc(len + 2);

	if (!y)
	{
		free(y);
		return (NULL);
	}
	*y = '\0';

	while (n / 10)
	{
		y[x] = (n % 10) + '0';
		n /= 10;
		x++;
	}

	y[x] = (n % 10) + '0';
	array_rev(y, len);
	y[x + 1] = '\0';

	return (y);
}

/**
  *_strcmp - compares two strings
  *@s1: first string
  *@s2: secong string
  *Return: 0 if identical otherwise the difference
  */
int _strcmp(char *s1, char *s2)
{
	int len1, len2, x;
	int com = 0;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (x = 0; s1[x]; x++)
	{
		if (s1[x] != s2[x])
		{
			com = s1[x] - s2[x];
			break;
		}
		else
			continue;
	}
	return (com);
}
