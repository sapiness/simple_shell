#include "main.h"

/**
 * _strlen - Checks the length of a string
 * @str: The string to be checked
 *
 * Return: On success, the length of the string.
 */
int _strlen(char *str)
{
	int length = 0;

	while (str[length])
		length++;

	return (length);
}
