/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:46:07 by majjig            #+#    #+#             */
/*   Updated: 2022/03/26 00:46:08 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lst(t_envlist *lst)
{
	while (lst)
	{
		free(lst -> stock);
		free(lst -> var_content);
		free(lst -> var_name);
		lst = lst -> next;
	}
}
