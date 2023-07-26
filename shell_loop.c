#include "shell.h"
/**
 * shell_loop - shell loop event handler
 * @sh: shell_t struct
 * @argv: argv
 * Return: void
 */

void shell_loop(shell_t *sh, char **argv)
{
	int error = 1, status, exit_flag = 1;

	while (error > 0)
	{
		error = getcmd(sh);
		/* DEBUG_INT(error) */
		if (error == FILE_ERROR)
			break;
		else if (error == SUP_LINE || error == LINE_ERROR)
			continue;
		if (trim(sh->buffer) == 1)
		{
			sh->argv = strtow(sh->buffer, ' ', &sh->argc);
			if (sh->argv)
			{
				status = is_builtin(sh);
				if (status != -1)
				{
					if (builtin(sh, status, &(sh->exit_status)) == -2)
					{
						exit_flag = 0;
						break;
					}
				}
				else
				{
					status = get_path(sh);
					if (status == 0)
						shell(sh, *argv);
					else
						sh->exit_status = print_error(sh, status);
				}
				Sh_free(sh);
			}
		}
	}
	Sh_free(sh);
	if (isatty(0) && exit_flag)
		_putchar('\n');
}

/**
 * getcmd - get cmd to exec
 * @sh: shell_t struct
 * Return: negative fail else success
 */
int getcmd(shell_t *sh)
{
	int error;
	char *ptr;

	if (sh->hold == NULL)
	{
		if (isatty(0))
			_puts("hicham$ ");
		error = _getline(0, &(sh->buffer));
		sh->line_count++;
		if (error == -1)
			return (FILE_ERROR);
		if (error == 0)
			return (END_OF_FILE);
		if (_strch(sh->buffer, ';'))
		{
			sh->hold = _split_line(sh->buffer, sh->shell);
			sh->tmp = sh->hold; /* magic line */
			if (sh->hold == NULL)
				return ((sh->exit_status = 2));
			return (SUP_LINE);
		}
		return (NORMAL_LINE);
	}
	else
	{
		memdel(sh->buffer);
		sh->buffer = _strdup(*(sh->tmp));
		ptr = *(sh->tmp);
		sh->tmp = sh->tmp + 1;
		free(ptr);
		if (!*(sh->tmp))
		{
			memdel(*(sh->tmp));
			free(sh->hold);
			sh->hold = NULL;
			return (END_OF_LINE);
		}
		return (NORMAL_LINE);
	}
}
