#include "shell.h"

/**
 * _getenv - get all env varible to execve function
 * @sh: shell_t struct to store env
 * Return: 0 on success -1 on error
 */
int _getenv(shell_t *sh)
{
	int len;
	char **s = environ;
	int i;

	for (sh->env_size = 0; *s; s++, sh->env_size++)
		;
	s = environ;
	sh->env = (char **)malloc(sizeof(char *) * (sh->env_size + 1));
	if (!sh->env)
		return (-1);
	_memset2(sh->env, sh->env_size + 1);
	for (i = 0; *s; s++, i++)
	{
		len = _strlen(*s);
		sh->env[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!(sh->env[i]))
			return (-1);
		_strcpy(sh->env[i], *s);
	}
	return (0);
}

