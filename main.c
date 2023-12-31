#include "main.h"

/**
 * main - Displays the shell prompt.
 * @argc: Number of command line arguments.
 * @argv: Command line arguments.
 * @envp: Environment variables.
 *
 * Return: On success (0).
 */
int main(int argc, char *argv[], char *envp[])
{
	ssize_t bytes_read = 0;
	char **tokens, *path = NULL, *line;
	int tokens_count, cmd_from;
	size_t n = 0;
	pid_t child_p;

	cmd_from = isatty(STDIN_FILENO);
	while (1)
	{
		if (cmd_from == 1)
			cprompt(argv[argc - 1]);
		line = NULL;
		bytes_read = getline(&line, &n, stdin);
		if (feof(stdin))
		{
			sfree_memory(line);
			break; }
		tokens_count = cc_input_exit(line, bytes_read);
		if (tokens_count == 0)
		{	sfree_memory(line);
			continue; }
		tokens = tokenize(line);
		if (!is_valid_path(tokens[0], &path, envp))
		{
			child_p = fork();
			if (child_p == 0)
				if (execve(path, tokens, envp) == -1)
					perror(argv[0]);

			wait(NULL);
			sfree_memory(path);
		}
		else
			perror(argv[0]);
		sfree_memory(line);
		dfree_memory(tokens, tokens_count + 1);
		fflush(stdout);
	}
	return (0);
}
