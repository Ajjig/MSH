/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:06:49 by majjig            #+#    #+#             */
/*   Updated: 2021/11/07 17:15:58 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len;
	char		*new_src;

	new_src = (char *) src;
	len = ft_strlen(dst) + ft_strlen(new_src);
	if (size <= (size_t)ft_strlen(dst))
		return (ft_strlen(new_src) + size);
	while (*dst)
		dst++;
	i = 0;
	while ((i < size - (len - ft_strlen(new_src)) - 1) && src[i])
	{
		dst[i] = new_src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}
