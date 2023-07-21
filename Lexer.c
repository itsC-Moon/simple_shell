#include "shell.h"
/**
 * **strtow - splits a string into words
 * @str: input string
 * @d: the delimeter
 * @len: len of 2d array
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(const char *str, char d, int *len)
{
	int i = 0, j = 0, k = 0, m = 0, numwords = 0, l = 0;
	char **arg = NULL;

	if (str == NULL || str[0] == 0)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == d)
			i++;
		while (str[i] && str[i] != d)
			i++;
		numwords++;
		if (!(str[i]))
			break;
	}
	arg = (char **)malloc(sizeof(char *) * (numwords + 1));
	if (!(arg))
		return (NULL);
	_memset2(arg, numwords + 1);
	i = 0;
	k = 0;
	while (str[i])
	{
		for (j = i, m = 0; str[i] && str[i] != d; i++)
			m++;
		arg[k] = (char *)malloc(sizeof(char) * (m + 1));

		for (l = 0; str[j] && str[j] != d; j++, l++)
			arg[k][l] = str[j];
		arg[k][l] = '\0';
		k++;
		while (str[i] && str[i] == d)
			i++;

		if (!(str[i]))
			break;
	}
	*len = k;
	return (arg);
}
/**
 * get_path - get path of command
 * @sh: shell_t struct
 * Return: return 0 on success and -1 n error
 */
int get_path(shell_t *sh)
{
	char **path_agr;
	char buffer[1024] = {0};
	int len;
	char *path;
	int flag;
	int i;

	flag = -1;
	get_env_val(sh);
	if (access(*(sh->argv), F_OK) == 0)
	{
		if (access(*(sh->argv), X_OK) != 0)
			return (-2);
		sh->cmd = _strdup(*(sh->argv));
		return (0);
	}
	path = getenv("PATH");
	if (!path)
		return (-1);
	path_agr = strtow(path, ':', &len);
	for (i = 0; i < len; i++)
	{
		_strcpy(buffer, path_agr[i]);
		_strcat(buffer, "/");
		_strcat(buffer, *(sh->argv));
		if (access(buffer, F_OK) == 0)
		{
			if (access(buffer, X_OK) != 0)
			{
				flag = -2;
				break;
			}
			sh->cmd = _strdup(buffer);
			flag = 0;
			break;
		}
	}
	free2d(path_agr, len);
	free(path_agr);
	return (flag);
}

/**
 * get_env_val - get varible value
 * @sh: shell_t struct
 * Return: void
 */
void get_env_val(shell_t *sh)
{
	s_list *s_ptr;
	char *ptr;
	int i;

	for (i = 0; i < sh->argc; i++)
	{
		ptr = _strch(sh->argv[i], '$');
		if (ptr == NULL || _strlen(ptr) == 1)
			continue;

		s_ptr = searchlist(sh->t_list, ptr + 1);
		if (!s_ptr)
		{
			sh->argv[i] = emptystring(sh->argv[i]);
			continue;
		}
		ptr = _strch(s_ptr->env, '=');
		free(sh->argv[i]);
		sh->argv[i] = _strdup(ptr + 1);
	}
}
/**
 * check_dir - check dir for command
 * @bin: dir
 * @command: command
 * Return: full path to command
 */
char *check_dir(char *bin, char *command)
{
	DIR *folder;
	struct dirent *item;
	char *path;

	path = NULL;
	folder = opendir(bin);
	if (!folder)
		return (NULL);
	while ((item = readdir(folder)))
	{
		if (_strcmp(item->d_name, command) == 0)
		{
			path = _join(bin, item->d_name, "/");
			break;
		}
	}
	closedir(folder);
	return (path);
}
