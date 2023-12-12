#include "main.h"

/**
 * cc_input_exit - Removes '\n' from input string and
 * checks if the input is "exit" or "EOF".
 * @i_b: The buffer that holds the input from user.
 * @b_r: The length of the input from user.
 *
 * Return: Nothing.
 */
void cc_input_exit(char *i_b, ssize_t b_r)
{
	int i;

	for (i = 0; i_b[i]; i++)
		if (i_b[i] == '\n')
			i_b[i] = '\0';

	if (strcmp(i_b, "exit") == 0 || b_r == 0)
		exit(0);
}
