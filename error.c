#include "shell.h"

/**
 * error - error func
 * @sh: shell_t struct
 * @error: error message
 * @status: exit status
 * Return: status
 */
int error(shell_t *sh, char *error, int status)
{
	_puts_fd(2, sh->shell);
	_puts_fd(2, ": ");
	_putnbr_fd(2, sh->line_count);
	_puts_fd(2, ": ");
	_puts_fd(2, *(sh->argv));
	_puts_fd(2, ": ");
	_puts_fd(2, error);

	return (status);
}
/**
 * print_error - error function
 * @sh: shell_t struct
 * @code: error code
 * Return: error status
 */
int print_error(shell_t *sh, int code)
{
	if (code == -1)
		return (error(sh, "command not found\n", 127));
	else if (code == -2)
		return (error(sh, "Permission denied\n", 126));
	else if (code == -3)
		return (error(sh, "Illegal number", 2));
	return (-1);
}
