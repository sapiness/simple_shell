<<<<<<< HEAD
#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
=======
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
			if (child_p > 0)
				wait(NULL);
		}
		else
			perror(argv[0]);

		sfree_memory(path);
		dfree_memory(tokens, tokens_count + 1);
	}
>>>>>>> 584dcc611293be2926352f92d85038f61811a583
}
