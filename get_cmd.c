/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:43:42 by majjig            #+#    #+#             */
/*   Updated: 2022/03/25 03:12:43 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_error(char *s)
{
	printf("\x1b[31m%s: command not found\n\x1b[37m", s);
	g_variable.g_exites = 1;
	return ;
}

char	*path_joiner(char *path, char *cmd)
{
	char	*ret;
	char	*slash;

	slash = ft_strjoin(path, "/");
	ret = ft_strjoin(slash, cmd);
	free(slash);
	return (ret);
}

char	*is_in_list(char *cmd, char **others, char *path, int i)
{
	if (is_builtin(cmd))
		return (ft_strdup(is_builtin(cmd)));
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path = getenv("PATH");
	if (path == NULL)
		return (set_error(cmd), NULL);
	others = ft_split(path, ':');
	while (others[i])
	{
		path = path_joiner(others[i++], cmd);
		if (access(path, F_OK) != -1)
		{
			i = 0;
			while (others[i])
				free(others[i++]);
			free(others);
			return (path);
		}
		free(path);
	}
	i = 0;
	while (others[i])
		free(others[i++]);
	return (free(others), set_error(cmd), NULL);
}

char	*args_joiner(char *args, char *new)
{
	char	*joined;
	char	*space;

	if (args == NULL)
		return (ft_strdup(new));
	space = ft_strjoin(args, " ");
	joined = ft_strjoin(space, new);
	free(args);
	free(space);
	return (joined);
}

t_command	*get_cammand(char **buff, int i, int tmp, t_envlist *lst)
{
	t_command	*command;
	int			ai;

	ai = 0;
	command = init_cmd(buff);
	while (buff[i])
	{
		parser(command, buff, &i, &ai);
		if (buff[i] && buff[i][0] == RED_PIPE && ++i)
		{
			command -> next = get_cammand(buff, i, i, lst);
			break ;
		}
		if (buff[i] && ft_strchr(REDIRECTIONS, buff[i][0]))
		{
			command -> redirection = ft_strdup(buff[i++]);
			gen_files(command, buff[i - 1], buff[i]);
		}
		else if (buff[i] && command -> program == NULL)
			command -> program = is_in_list(buff[i], NULL, NULL, 0);
		i++;
	}
	if (!ft_strcmp(command->redirection, "<<"))
		command->heredoc = heredoc(command, lst);
	command -> args[ai] = NULL;
	return (command -> execve = get_execve(buff, tmp), command);
}
