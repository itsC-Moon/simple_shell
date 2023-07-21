#include "shell.h"

/**
 * addnode - add node to linken list
 * @list_t: linken list head and tail and size
 * @str: value to add
 * Return: add node
 */
s_list *addnode(list *list_t, char *str)
{
	s_list *node;

	node = (s_list *)malloc(sizeof(s_list));
	if (!node)
		return (NULL);

	node->env = _strdup(str);
	node->next = NULL;
	if (list_t->head == NULL)
	{
		list_t->head = node;
		list_t->tail = node;
	}
	else
	{
		list_t->tail->next = node;
		list_t->tail = node;
	}
	list_t->size++;
	return (node);
}
/**
 * __getenv - get environ from shell
 * @env: environ
 * Return: linken list
 */
list *__getenv(char **env)
{
	list *list_t;
	char **s;

	s = env;
	list_t = (list *)malloc(sizeof(list));
	list_t->head = NULL;
	list_t->tail = NULL;
	list_t->size = 0;
	while (*s)
	{
		addnode(list_t, *s);
		s++;
	}
	return (list_t);
}
/**
 * freelist - free linken list
 * @list_t: linken list head and tail and size
 * Return: 1
 */
int freelist(list *list_t)
{
	s_list *node;
	s_list *tmp;

	node = list_t->head;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp->env);
		free(tmp);
	}
	free(list_t);
	return (1);
}
/**
 * searchlist - search a linken list
 * @list_t: linken list head and tail and size
 * @str: string to search for it
 * Return: s_list node if found else null
 */
s_list *searchlist(list *list_t, char *str)
{
	s_list *node;

	node = list_t->head;
	while (node != NULL)
	{
		if (_strncmp(node->env, str, _strlen(str)) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * edit_varible -test
 * @node: test
 * @value:test
 * Return: test
 */
void edit_varible(s_list *node, char *value)
{
	char *new;
	int len;
	int i;

	i = 0;
	while (node->env[i] != '=')
		i++;
	len = _strlen(value);
	/* 1 for \0 and 1 for = */
	new = (char *)malloc(sizeof(char) * (i + len + 1) + 1);
	i = 0;
	while (node->env[i] != '=')
	{
		new[i] = node->env[i];
		i++;
	}
	new[i] = '=';
	i++;
	while (*value)
	{
		new[i] = *value;
		value = value + 1;
		i++;
	}
	new[i] = '\0';
	free(node->env);
	node->env = new;
}
