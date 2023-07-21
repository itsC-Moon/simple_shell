#include "shell.h"
#include <string.h>
/**
 * to_array - linken list to 2d array
 * @t_list: linken list
 * Return: 2d array
 */
char **to_array(list *t_list)
{
	s_list *tmp;
	char **env;
	int i;

	tmp = t_list->head;
	env = (char **)malloc(sizeof(char *) * (t_list->size + 1));
	i = 0;
	while (tmp != NULL)
	{
		env[i] = strdup(tmp->env);
		i++;
		tmp = tmp->next;
	}

	env[i] = NULL;
	return (env);
}
