#include "shell.h"
/**
 * my_export - export shell varible
 * @sh: shell_t struct
 * Return: 0 on success -1 on error
 */
int my_export(shell_t *sh)
{
	char *ptr;

	ptr = _strch(sh->argv[1], '=');
	if (!ptr)
		return (-1);

	addnode(sh->t_list, sh->argv[1]);
	return (0);
}

/**
 * my_env - list shell varible
 * @sh: shell_t struct
 * Return: void
 */
int my_env(shell_t *sh)
{
	s_list *tmp;

	tmp = sh->t_list->head;
	while (tmp != NULL)
	{
		_puts(tmp->env);
		_putchar('\n');
		tmp = tmp->next;
	}
	return (0);
}
