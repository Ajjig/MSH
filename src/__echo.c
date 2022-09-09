/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:47:03 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/03/25 00:47:22 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	__echo(t_command *commad)
{
	int	i;
	int	tablen;

	tablen = ft_tab_len(commad->args);
	i = 0;
	if (!commad->args[0])
	{
		if (!commad->options)
			printf("\n");
	}
	else if (commad->options && !ft_strcmp(commad->options, "-n"))
	{
		while (i < tablen - 1)
			printf("%s ", commad->args[i++]);
		if (tablen >= 1)
			printf("%s", commad->args[i]);
	}
	else if (!commad->options && commad->args)
	{
		while (i < tablen - 1)
			printf("%s ", commad->args[i++]);
		if (tablen >= 1)
			printf("%s\n", commad->args[i]);
	}
	return (0);
}
