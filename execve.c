#include "minishell.h"

char **linked_double(t_envlist *lst)
{
	int		len;
	t_envlist	*tmp;
	char	**buff;

	len = 0;
	tmp = lst;
	while (tmp)
	{
		len++;
		tmp = tmp -> next;
	}
	buff = (char **) malloc ((len + 1) * sizeof(char *));
	len = 0;
	while (lst)
	{
		buff[len++] = lst -> stock;
		lst = lst -> next;
	}
	buff[len] = NULL;
	return buff;
}

char *exeve_handler(t_command *command, t_envlist *lst)
{
	char **buff;
	char *const db[] = {command->program, command->options, NULL};
 	buff = linked_double(lst);

	int pid = fork();
	if (pid == 0)
	{
		execve(command -> program, db, buff);
	}
	else
		wait(NULL);
	return (free(buff), NULL);
}
