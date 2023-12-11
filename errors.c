#include "main.h"

/**
 * handle_error - Checks for system call errors (read and write)
 * @err_value: The value returned by the system call.
 *
 * Return: Nothing.
 */
void handle_error(int err_value)
{
	if (err_value == -1)
	{
		perror("Error");
	}
}
