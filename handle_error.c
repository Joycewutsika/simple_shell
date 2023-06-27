#include "shell.h"

/**
  *print_error - displays unique error messages.
  *@input: input
  *@c: count of loop
  *@argv: argument vector
  */
void print_error(char *input, int c, char **argv)
{
	char *err_msg;

	PRINT(argv[0]);
	PRINT(": ");
	err_msg = _itoa(c);
	PRINT(err_msg);
	free(err_msg);
	PRINT(": ");
	PRINT(input);
	PRINT(": command not found\n");
}

/**
  *_prerror - prints custom error message
  *@argv: argument vector
  *@c: error count
  *@cmd: command strings
  */
void _prerror(char **argv, int c, char **cmd)
{
	char *err_msg = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err_msg);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(err_msg);
}

/**
  *error_file - custom error message for file errors
  *@argv: argument vector
  *@c: error count
  */
void error_file(char **argv, int c)
{
	char *err_msg = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(err_msg);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(err_msg);
}
