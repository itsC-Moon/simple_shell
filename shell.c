#include "shell.h"
/**
 * Sh_free - free shell_t pointer
 * @sh: shell_t struct
 * Return: void
 */
void Sh_free(shell_t *sh)
{
	int i;

	if (sh->cmd)
	{
		free(sh->cmd);
		sh->cmd = NULL;
	}
	if (sh->argv)
	{
		for (i = 0; i < sh->argc; i++)
			free(sh->argv[i]);
		free(sh->argv);
		sh->argv = NULL;
	}
}
/**
 * shell -The Shell
 * @sh: shell_t struct
 * @argv: name of program
 * Return: int
 */
int shell(shell_t *sh, char *argv)
{
	pid_t pid;
	char **env;

	pid = fork();
	if (pid == 0)
	{
		env = to_array(sh->t_list);
		if (execve(sh->cmd, sh->argv, env) == -1)
		{
			_puts(argv);
			_puts(" : ");
			perror(*(sh->argv));
			Sh_free(sh);
			free2d(sh->env, sh->env_size);
			free2d(env, sh->t_list->size);
			return (-1);
		}
	}
	else
	{
		wait(&sh->exit_status);
		sh->exit_status = WEXITSTATUS(sh->exit_status);
	}

	return (1);
}
