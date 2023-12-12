#include "main.h"

/**
 * sfree_memory - Frees a single pointer memory
 * @mem_address: Memory address to be freed.
 *
 * Return: Nothing.
 */
void sfree_memory(char *mem_address)
{
	if (mem_address)
		free(mem_address);
}

/**
 * dfree_memory - Frees a double pointer memory.
 * @mem_address: The memory address to be freed.
 * @size: Length of second level pointer.
 *
 * Return: Nothing.
 */
void dfree_memory(char **mem_address, int size)
{
	int i;

	if (mem_address)
	{
		for (i = size - 1; i >= 0; i--)
			free(mem_address[i]);

		free(mem_address);
	}
}
