/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:52:50 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/03/25 00:58:54 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_utils(t_command *command)
{
	char	*user;
	int		ret;

	if (command->args && (command -> args[0] == NULL \
		|| ft_strcmp(command -> args[0], "~") == 0))
	{
		user = getenv("USER");
		chdir("/Users/");
		ret = chdir(user);
		if (ret != 0)
			puts("cd: no such file or directory");
	}
	else
		ret = chdir(command -> args[0]);
	return (ret);
}

int	__cd__(t_command *command, t_envlist *lst)
{
	char	*wd;
	int		ret;

	ret = cd_utils(command);
	wd = getcwd(NULL, 0);
	if (ret != 0)
	{
		puts("cd: no such file or directory");
		return (1);
	}
	else
	{
		free(command->args[0]);
		command->args[0] = ft_strjoin("PWD=", wd);
		__export(lst, command);
	}
	free(wd);
	return (0);
}
