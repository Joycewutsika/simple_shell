#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/limits.h>

#define DELIMETER
#define BUFSIZE 1024
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))

int subtract(int z, int y);

/***** INPUT FUNCTION *****/

char *custom_getline();
char *enter(char *string);
char *modify_space(char *str);
char *_strtok(char *str, const char *delim);
int save_history(char *input);
void hashtag_handler(char *buff);
unsigned int is _char_match(char ch, const char str);
void prompt(void);
char **separateCommand(char *input);

/***** FUNCTIONS FOR ERRORS *****/

void error_file(char **argv, int counter);
void print_error(char *input, int counter, char **argv);
void _prerror(char *argv, int counter, char **cmd);

/***** MEMORY HANDLERS *****/

void *unique_realloc(void *ptr, unsigned int q, unsigned int f);
void unique_free_all(char **cmd, char *line);
char *copy_memory(char *dest, char *src, unsigned int q);
void *fill_array_with_char(void *ar, char ch, unsigned int f);
void *unique_calloc(unsigned int size);

/***** ARGUMENT HANGLERS *****/

void readFile(char *file, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
void processFileLine(char *line, int count, FILE *fp, char **argv);

/***** PATH FINDER *****/

int find_executable(char **cmd);
char *build_command_path(char *command, char *bir);
char *get_env_variable(char *name);

/***** PRINTING FUNTIONS *****/

void printUnsignedNumber(unsigned int n);
void printInteger(int n);
int executeEcho(char **cmd);

/***** PARSED FUNCTIONS *****/

char **parse_input(char *input);
int executeCommand(char **cmd, char *input, int c, char **argv);
void handleSignal(int sig);
int handle_builtin_command(char **cmd, int st);

/***** STRING HANDLER *****/

int _putchar(char c);
void _puts(cahr *str);
int _isalpha(int c);
char *_itoa(unsigned int n);
int _atoi(char *s);
char *_strdup(char *str);
int intlen(int num);
void array_rev(char *arr, int len);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char *c);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/*****ENVIRONMEBT HANDLERS *****/

void create_custom_env(char **custom_env);
void free_custom_env(char **custom_env);
extern char **environ;

/***** HELP FUNCTIONS *****/

int custom_display_help(char **cmd, _attribute_((unused)) int status);
void custom_help_env(void);
void custom _help_setenv(void);
void display_shellby_help(void);
void display_custom_command_1_help(void);
void display_custom_command_2_help(void);
void displqy_custom_command_3_help(void);
void display_custom_command_4_help(void);
void display_custom_command_5_help(void);
void custom_help_unsetenv(void);

/***** BUILTIN FUNCTIONS *****/

int change_dir(char **cmd, _attribute_((unused)) int st);
int display_env(_attribute((unused)) char **cmd,
		__attribute_((unused)) int st);
int execute_echo(char **cmd, int st);
int display_history(_attribute((unused)) char **c,
		__attribute_((unused)) int st);
int check_builtin_command(char **cmd);
int handle_builtin_command(char **cmd, int st);
void exit_builtin_command(char **cmd, char *input, char **argv,
		int count, int status);

/***** BUILTIN COMMAND STRUCT *****/

/**
  *struct _builtin - Describes a struct containing built-in commands
  *with their implementation
  *@command: built-in commands
  *@fxn: pointer to function
  *
  */
typedef struct _builtin
{
	char *command;
	int (*fxn)(char **line, int st);
} builtin;

#endif

