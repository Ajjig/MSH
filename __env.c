/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:44:42 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/03/25 04:54:01 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_printer(t_envlist *lst)
{
	if (!lst)
		return (1);
	while (lst != NULL)
	{
		printf("declare -x %s=\"%s\"\n", lst->var_name, lst->var_content);
		lst = lst->next;
	}
	return (0);
}

int	__env(t_envlist *lst)
{
	if (!lst)
		return (1);
	while (lst != NULL)
	{
		printf("%s=%s\n", lst->var_name, lst->var_content);
		lst = lst->next;
	}
	return (0);
}

t_envlist	*__env__init(char **envp)
{
	int			i;
	t_envlist	*lst;

	lst = NULL;
	i = 0;
	g_variable.is_running = 0;
	g_variable.g_exites = 0;
	if (envp[0] == NULL)
	{
		ft_lstadd_back(&lst, ft_lstnew("PATH=/usr/local/bin:/bin:/usr/bin:."));
		return (lst);
	}
	while (envp[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(envp[i]));
		i++;
	}
	return (lst);
}
