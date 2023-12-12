#include "main.h"

/**
 * _strtok - Tokenizes a given string based in a certain delimeter.
 * @str: The string to be tokenized.
 * @delim: The delimeter(s).
 *
 * Return: On success, a pointer to the current token found.
 */
char *_strtok(char *str, const char *delim)
{
	int i, j;
	static char *start_from;

	if (str == NULL)
	{
		if (start_from == NULL)
			return (NULL);
		str = start_from;
	}

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				str[i] = '\0';
				for (i = i + 1; str[i] == ' '; i++)
					; /* Handle multiple whitespaces in-between */
				start_from = &str[i];
				return (str);
			}
		}
	}

	start_from = NULL;

	return (str);
}
