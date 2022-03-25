/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:15:48 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/03/25 19:03:30 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_execve(char **buff, int i)
{
	int		len;
	char	**execve;
	int		j;

	j = 0;
	len = i;
	while (buff[len] && !ft_strchr(REDIRECTIONS, buff[len][0]))
		len ++;
	if (buff[len] == NULL && i == 0)
		return (buff);
	execve = (char **) malloc (((len - i) + 1) * sizeof(char *));
	while (j <= len - i)
		execve[j++] = ft_strdup(buff[i++]);
	execve[j] = NULL;
	return (execve);
}
