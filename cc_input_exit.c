#include "main.h"

/**
 * cc_input_exit - Removes '\n' from input string and
 *                 checks if the input is "exit" or "EOF".
 * @i_b: The buffer that holds the input from user.
 * @b_r: The length of the input from user.
 *
 * Return: Nothing.
 */
void cc_input_exit(char *i_b, ssize_t b_r)
{
	int i = 0;

	while (i_b[0] == ' ')
		i_b++; /* Remove leading white spaces */

	for (i = 0; i_b[i]; i++)
		if (i_b[i] == '\n')
			i_b[i] = '\0';

	for (i = i - 2; i_b[i] == ' '; i--)
		i_b[i] = '\0'; /* Remove trailing whitespaces */

	if (strcmp(i_b, "exit") == 0 || b_r == -1)
		exit(0);

	/*if (b_r == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}*/
}
