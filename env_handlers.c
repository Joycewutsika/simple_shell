#include "shell.h"

/**
 * create_custom_env - Creates a custom env variables
 * @custom_env: Array to store custom env variables
 */

void create_custom_env(char **custom_env)
{
	int g;

	for (g = 0; environ[g]; g++)
		custom_env[g] = _strdup(environ[g]);
	custom_env[g] = NULL;
}

/**
 * free_custom_env - Frees the memory of the created custom env variables array
 * @custom_env: Array of custom env variables
 */
void free_custom_env(char **custom_env)
{
	int g;

	for (g = 0; custom_env[g]; g++)
	{
		free(custom_env[g]);
	}
}

