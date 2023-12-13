#include "main.h"

/**
 * loop_for - Helper function to check for how many loops
 *            would be required to run through a token.
 * @str: The string to be tokenized.
 * @delim: The delimeter to check against the string.
 *
 * Return: The total number of strings in between the delimeters.
 */
int loop_for(char *str, char delim)
{
	int i, count = 0;

	while (str[0] == ' ')
		str++;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == delim)
		{
			count++;
			for (i = i + 1; str[i] == ' '; i++)
				;
		}
	}

	if (i == 0)
		return (0);

	return (count + 1);
}

/**
 * is_valid_path - checks that a given command can be found
 *                 in the path environment variable.
 * @command: The given command.
 * @path: Pointer to the variable that will eventually hold the full path.
 * @env: Evironment variables.
 *
 * Return: On success (0). On failure (-1).
 */
int is_valid_path(char *command, char **path, char **env)
{
	int i, env_length;
	char *env_str = NULL, *env_t = NULL;

	if (command[0] == '/')
	{
		*path = malloc(strlen(command) + 1);
		strcpy(*path, command);
		if (access(*path, F_OK) == 0)
			return (0);
		sfree_memory(*path); /* PATH FREED */
		return (-1);
	}
	for (i = 0; env[i]; i++)
	{
		if (env[i][0] == 'P' && env[i][3] == 'H')
		{
			env_str = malloc(_strlen(&env[i][5]) + 1);
			strcpy(env_str, &env[i][5]);
			break;
		}
	}

	env_length = loop_for(env_str, ':');
	for (i = 0; i < env_length; i++)
	{
		env_t = (i == 0) ? strtok(env_str, ":") : strtok(NULL, ":");
		*path = malloc(strlen(env_t) + strlen(command) + 2);
		strcpy(*path, env_t);
		strcat(*path, "/");
		strcat(*path, command);
		if (access(*path, F_OK) == 0)
		{
			sfree_memory(env_str);
			return (0);
		}
		sfree_memory(*path);
	}
	/**path = NULL;*/
	sfree_memory(env_str);
	return (-1);
}
