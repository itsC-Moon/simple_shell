#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @argv: arg value
 * Return: 0 or 1 or -1
 */
int main(int ac, char **argv)
{
	shell_t *sh;
	int exit_status;

	exit_status = 1;
	(void)ac;
	sh = (shell_t *)malloc(sizeof(shell_t));
	sh->shell = (*argv);
	shell_init(sh);
	sh->t_list = __getenv(environ);


	shell_loop(sh, argv);
	free(sh->buffer);
	freelist(sh->t_list);
	exit_status = sh->exit_status;

	free(sh);
	exit(exit_status);
}
