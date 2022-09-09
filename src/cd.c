/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:52:50 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/03/26 18:08:55 by majjig           ###   ########.fr       */
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
		free(*(command->args));
		*(command->args) = ft_strjoin("PWD=", wd);
		*(command->args + 1) = NULL;
		__export(lst, command);
	}
	free(wd);
	return (0);
}
