#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>

#include <assert.h>
/* #include <sys/socket.h> */
#include <signal.h>
#define DEBUG_STR(x) printf("%s=%s\n", #x, x)
#define DEBUG_INT(x) printf("%s=%d\n", #x, x)
#define READSIZE 64
#define FREE_BUFFER 1
#define KEEP_BUFFER 0

#define LINE_ERROR 2
#define END_OF_LINE 3
#define END_OF_FILE 0
#define FILE_ERROR -1
#define STILL_MORE 1
#define NORMAL_LINE 12
#define SUP_LINE 13
#define EXIT_SHELL -1
extern char **environ;
/**
 * struct s_list - linken list
 * @env: env value
 * @next: next node
 */
typedef struct s_list
{
	char *env;
	struct s_list *next;

} s_list;
/**
 * struct list - list
 * @head: list begin
 * @tail: list end
 * @size: size
 */
typedef struct list
{
	s_list *head;
	s_list *tail;
	int size;
} list;
/**
 * struct shell_t - shell_t struct
 * @argc: arg count
 * @argv: command line arg
 * @cmd: command
 * @buffer: user input buffer
 * @env: environ to pass it to execve function
 * @env_size: size of environ
 * @exit_status: exit status still under test { :D }
 * @line_count: exit status still under test { :D }
 * @t_list: exit status still under test { :D }
 * @hold: exit status still under test { :D }
 * @tmp: exit status still under test { :D }
 * @shell: exit status still under test { :D }
 */
typedef struct shell_t
{
	char *shell;
	char *buffer;
	char *cmd;
	char **tmp;
	char **argv;
	char **env;
	int env_size;
	int argc;
	int line_count;
	int exit_status;
	list *t_list;
	char **hold;
} shell_t;

char *path(char *);
int _getline(int fd, char **line);
int shell(shell_t *, char *);
int getcmd(shell_t *sh);

void ffree(shell_t *sh);
void free2d(char **ptr, int size);
void _memset2(char **, int);
void Sh_free(shell_t *sh);
void *memdel(void *ptr);
/* print */

int _putchar(char);
int _puts(char *);
void subprint(char *str, char c);
void _puts_fd(int fd, char *str);
void _putnbr_fd(int fd, int nb);
int _putchar_fd(int fd, char c);
/* string */
char *trim_line(char *str, int flag);
int _strlen(char *);
char *_strch(char *str, char c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char **strtow(const char *str, char d, int *len);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdfup(char *str, int flag);
char *_strdup(char *str);
int empty(char *);
int trim(char *);
int _isspace(char);
char *emptystring(char *ptr);
int _getenv(shell_t *sh);
int get_path(shell_t *sh);
char *_join(char *dest, char *src, char *sep);
char *check_dir(char *bin, char *command);
int count_word(char *str, char d);
/* builtin */

int my_export(shell_t *sh);
int my_cd(shell_t *sh);
int my_exit(shell_t *sh);
int my_echo(shell_t *sh);
int my_env(shell_t *sh);
int is_builtin(shell_t *sh);
int builtin(shell_t *sh, int code, int *status);
void shell_loop(shell_t *sh, char **argv);
void shell_init(shell_t *sh);
/*Debug*/

void print2D(shell_t *sh);
/* list */
s_list *addnode(list *list_t, char *str);
char **to_array(list *t_list);
list *__getenv(char **env);
int freelist(list *list_t);
s_list *searchlist(list *list_t, char *str);
void edit_varible(s_list *node, char *value);
void printList(s_list *head);
void get_env_val(shell_t *sh);
/* token */
int get_next_token(shell_t *sh, char d, int *i);
/* memory */
void *_realloc(void *oldptr, int oldsize, int newsize);
/* error */
int print_error(shell_t *sh, int code);
/* outils */
char **_split_line(char *buffer, char *argv);
int error_line(char *line, char *argv);
int _atoi(char *s);
#endif /*SHELL_H_*/
