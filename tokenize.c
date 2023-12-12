#include "main.h"

/**
 * tokenize - Converts a string into tokens
 * @input_buf: String to be converted.
 *
 * Return: On success, a pointer to an array of
 *         tokens ending with NULL.
 */
char **tokenize(char *input_buf)
{
	int i, token_len = 0;
	char **token_mem = NULL;
	char *token = NULL;

	while (input_buf[0] == ' ')
		input_buf++;

	token_len = loop_for(input_buf, ' ') + 1;

	token_mem = malloc(token_len * sizeof(char *));
	if (token_mem == NULL)
		perror("Error allocating token memory");

	for (i = 0; i < token_len - 1; i++)
	{
		if (i == 0)
			token = _strtok(input_buf, " ");
		else
			token = _strtok(NULL, " ");
		token_mem[i] = malloc((_strlen(token) + 1) * sizeof(char));
		if (token_mem[i] == NULL) /* Check if allocation failed*/
		{
			for ( ; i >= 0; i--)
				free(token_mem[i]);
		}
		strcpy(token_mem[i], token);
	}
	token_mem[i] = NULL;

	return (token_mem);
}
