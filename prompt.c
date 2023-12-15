#include "main.h"

/**
 * cprompt - Prompts the user to type something.
 * @filename: Name of the shell program.
 *
 * Return: Nothing.
 */
void cprompt(char *filename)
{
	char prompt[] = "$ ";
	ssize_t bytes_written;

	bytes_written = write(STDOUT_FILENO, prompt, _strlen(prompt));
	handle_error(bytes_written, filename);
}
