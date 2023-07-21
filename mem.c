#include "shell.h"
/**
 * _memset2 - set ** pointer to keep valgrind happy
 * @src: the input **
 * @size: size of src
 * Return: none
 */
void _memset2(char **src, int size)
{
	int i;

	for (i = 0; i < size; i++)
		src[i] = NULL;
}
/**
 * **ffree - free shell_t
 * @sh: shell_t
 * Return: none
 */
void ffree(shell_t *sh)
{
	int i;

	for (i = 0; i < sh->argc; i++)
		free(sh->argv[i]);
	free(sh->argv);
}
/**
 * free2d - free
 * @ptr: 2d array of string
 * @size: size of array
 * Return:
 */
void free2d(char **ptr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		free(ptr[i]);
}
/**
 * shell_init - init the shell_t struct
 * @sh: shell_t
 * Return: void
 */
void shell_init(shell_t *sh)
{
	sh->argc = 0;
	sh->argv = NULL;
	sh->env = NULL;
	sh->buffer = NULL;
	sh->cmd = NULL;
	sh->env_size = 0;
	sh->exit_status = 0;
	sh->line_count = 0;
	sh->hold = NULL;
	sh->t_list = NULL;
}
/**
 * memdel - delete memory chunk
 * @ptr: pointer to memory
 * Return: NULL
 */
void *memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}
