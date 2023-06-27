#include "shell.h"

/**
  *_strcpy - copies a string
  *@dest: destination
  *@src: source
  *Return: destination
  */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

/**
  *_strcat - concantenates two strings
  *@dest: first string
  *@src: second string
  *Return: first string + second string
  */
char *_strcat(char *dest, char *src)
{
	char *x = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (x);
}

/**
  *_strchr - locates character in a string
  *@s: string
  *@c: character
  *Return: pointer to character
  */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);
}

/**
  *_strncmp - compares characters of two strings
  *@s1: first string
  *@s2: second string
  *@n: amount of charcter
  *Return: 1 if string does not match, otherwise 0
  */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t x;

	if (s1 == NULL)
		return (-1);

	for (x = 0; x < n && s2[x]; x++)
	{
		if (s1[x] != s2[x])
		{
			return (1);
		}
	}
	return (0);
}

/**
  *_strdup - duplicates a string
  *@str: string
  *Return: duplicate string or Null if failed
  */
char *_strdup(char *str)
{
	size_t len, x;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}
	for (x = 0; x <= len; x++)
	{
		str2[x] = str[x];
	}
	return (str2);
}

