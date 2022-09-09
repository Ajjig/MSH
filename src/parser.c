/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:20:20 by majjig            #+#    #+#             */
/*   Updated: 2022/03/25 23:41:22 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_command *command, char **buff, int *i, int *ai)
{
	if (buff[*i] && *i == 1 && !ft_strcmp(buff[*i], "-n")
		&& !ft_strcmp(_ECHO, command -> program))
	{
		command -> options = ft_strdup(buff[*i]);
	}
	else if (buff[*i] && *i > 0 && !ft_strchr(REDIRECTIONS, buff[*i][0]))
	{
		command -> args[*ai] = ft_strdup(buff[*i]);
		*ai += 1;
		command -> args[*ai] = NULL;
	}
}
