#include "shell.h"

/**
  *executeCommand - executes command
  *@cmd: command
  *@input: input
  *@c: command not found
  *@argv: argument vector
  *Return: 1 (Null command), -1 (wrong command), 0 (success)
  */
int executeCommand(char **cmd, char *input, int c, char **argv)
{
	pid_t pid;
	int status;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			find_executable(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			print_error(cmd[0], c, argv);
			unique_free_all(cmd, input);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (0);
		else if (WEXITSTATUS(status) == 2)
			return (0);
		else if (WEXITSTATUS(status) == 127)
			return (127);
	}
	return (127);
}

/**
  *handleSignal - it makes sure nothing terminate our shell
  *@sig: signal alert
  */
void handleSignal(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n$");
	}
}
