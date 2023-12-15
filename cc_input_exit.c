#include "main.h"

/**
 * cc_input_exit - Removes '\n' from input string and
 *                 checks if the input is "exit" or "EOF".
 * @line: The buffer that holds the input from user.
 * @b_r: The length of the input from user.
 *
 * Return: On success, true length of line.
 */
int cc_input_exit(char *line, ssize_t b_r)
{
	int i = 0, token_length = 0;
	char *line_token, *line_copy;

	while (line[0] == ' ')
		line = &(line[1]); /* Remove leading white spaces */

	for (i = 0; line[i]; i++)
		if (line[i] == '\n')
			line[i] = '\0';

	for (i = _strlen(line) - 1; line[i] == ' '; i--)
		line[i] = '\0'; /* Remove trailing whitespaces */

	if (strcmp(line, "exit") == 0 || b_r == -1)
	{
		sfree_memory(line);
		exit(0);
	}

	line_copy = strdup(line);
	line_token = _strtok(line_copy, " ");
	while (line_token != NULL)
	{
		token_length++;
		line_token = _strtok(NULL, " ");
	}
	sfree_memory(line_copy);
	return (token_length);
}
