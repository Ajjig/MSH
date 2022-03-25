/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:17:55 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/03/25 01:17:56 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	gen_files(t_command *command, char *red, char *file)
{
	t_files	*new;
	t_files	*tmp;

	new = (t_files *) malloc (sizeof(t_files));
	new -> is_append = false;
	tmp = command -> files;
	if (!ft_strcmp(red, RED_APPEND))
		new -> is_append = true;
	new -> file = file;
	new -> next = NULL;
	if (command -> files == NULL)
	{
		command -> files = new;
		return ;
	}
	while (command -> files -> next)
		command -> files = command -> files -> next;
	command -> files -> next = new;
	command -> files = tmp;
}
