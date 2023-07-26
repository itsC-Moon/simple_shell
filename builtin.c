#include "shell.h"
/**
 * is_builtin - check if command is built in the shell
 * @sh: shell_t
 * Return: 0 on success -1on error
 */
int is_builtin(shell_t *sh)
{
	if (_strcmp(*(sh->argv), "cd") == 0)
		return (1);
	else if (_strcmp(*(sh->argv), "echo") == 0)
		return (2);
	else if (_strcmp(*(sh->argv), "exit") == 0)
		return (3);
	else if (_strcmp(*(sh->argv), "export") == 0)
		return (4);
	else if (_strcmp(*(sh->argv), "env") == 0)
		return (5);
	return (-1);
}

/**
 * builtin - run builtin commande
 * @sh: shell_t struct
 * @code: whitch commande need to be run
 * @status: status o that commande
 * Return: status
 */
int builtin(shell_t *sh, int code, int *status)
{
	switch (code)
	{
	case 1:
		*status = my_cd(sh);
		break;
	case 2:
		*status = my_echo(sh);
		break;
	case 3:
		*status = my_exit(sh);
		if (*status == -1)
		{
			*status = 2;
			return (-1);
		}
		return (-2);
	case 4:
		*status = my_export(sh);
		break;
	case 5:
		*status = my_env(sh);
		break;
	default:
		break;
	}
	return (*status);
}
/**
 * my_exit - exit from program
 * @sh: shell_t
 * Return: exit code 0 is default
 */
int my_exit(shell_t *sh)
{
	int code;

	if (sh->argv[1])
	{
		code = _atoi(sh->argv[1]);
		if (code == -1)
		{
			print_error(sh, -3);
			_puts_fd(2, ": ");
			_puts_fd(2, sh->argv[1]);
			_putchar_fd(2, '\n');
		}
		else
			return (code);
		return (-1);
	}
	return (0);
}
/**
 * my_cd - change current working dirctory
 * @sh: shell_t
 * Return: 0 on success -1 on error
 */
int my_cd(shell_t *sh)
{
	if (sh->argv[1])
	{
		if (chdir(*(sh->argv + 1)) == -1)
		{
			perror(*(sh->argv + 1));
			return (-1);
		}
	}
	else if (chdir(getenv("HOME")) == -1)
	{
		perror(*(sh->argv));
		return (-1);
	}
	return (0);
}
/**
 * my_echo - print to stdout
 * @sh: shell_t struct
 * Return: 0 on success -1 on error
 */
int my_echo(shell_t *sh)
{
	int i, flag = 1, n = 1;
	char *ptr;
	s_list *k;

	for (i = 1; i < sh->argc; i++)
	{
		if (_strcmp(sh->argv[i], "-n") == 0 && n)
		{
			flag = 0;
			continue;
		}
		else
			n = 0;
		ptr = _strch(sh->argv[i], '$');
		if (ptr == NULL || _strlen(ptr) == 1)
			_puts(sh->argv[i]);
		else
		{
			subprint(sh->argv[i], '$');
			k = searchlist(sh->t_list, ptr + 1);
			if (k)
				_puts(_strch(k->env, '=') + 1);
		}
		if (i + 1 != sh->argc)
			_putchar(' ');
	}
	if (flag)
		_puts("\n");
	return (0);
}
