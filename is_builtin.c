/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:14:10 by majjig            #+#    #+#             */
/*   Updated: 2022/03/25 21:14:11 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_builtin(char *cmd)
{
	static char	*all[] = {"echo", "cd", "pwd",
		"export", "unset", "env", "exit"};
	int			i;

	i = 0;
	while (i < 7)
		if (ft_strcmp(all[i++], cmd) == 0)
			return (all[--i]);
	return (NULL);
}
