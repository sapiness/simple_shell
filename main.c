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
	ssize_t bytes_read;
	ssize_t bytes_written;
	char input_buffer[1024] = {0};
	char prompt[] = "($) ";
	char **tokens;
	int tokens_count;
	char *path = NULL;
	pid_t child_p;
	(void)argc;

	while (1)
	{
		bytes_written = write(STDOUT_FILENO, prompt, _strlen(prompt));
		handle_error(bytes_written);

		bytes_read = read(STDIN_FILENO, input_buffer, 1024);
		handle_error(bytes_read);

		cc_input_exit(input_buffer, bytes_read);

		tokens_count = loop_for(input_buffer, ' ');
		tokens = tokenize(input_buffer);

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

		dfree_memory(tokens, tokens_count + 1);
	}
}
