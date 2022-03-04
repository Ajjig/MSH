/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:31:20 by majjig            #+#    #+#             */
/*   Updated: 2021/11/10 15:31:21 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	if (del == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}
	*lst = NULL;
}
