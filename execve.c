/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:18:03 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/03/25 23:29:25 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**linked_double(t_envlist *lst)
{
	int			len;
	t_envlist	*tmp;
	char		**buff;

	if (!lst)
		return (NULL);
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
	return (buff);
}

char	*exeve_handler(t_command *command, t_envlist *lst)
{
	char	**buff;
	int		pid;
	int		exits;
	int		i;

	i = 0;
	buff = linked_double(lst);
	pid = fork();
	if (pid == 0)
		execve(command -> program, command -> execve, buff);
	wait(&exits);
	if (WIFSIGNALED(exits))
	{
		if (WTERMSIG(exits) != 13)
			g_variable.g_exites = 128 + WTERMSIG(exits);
		if (WTERMSIG(exits) == SIGQUIT)
			printf(" Quit\n");
	}
	else
		g_variable.g_exites = WEXITSTATUS(exits);
	return (free(buff), NULL);
}
