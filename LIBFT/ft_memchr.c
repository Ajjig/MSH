/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:01:08 by majjig            #+#    #+#             */
/*   Updated: 2021/11/07 16:18:02 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	ch = (unsigned char) c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (NULL);
}
