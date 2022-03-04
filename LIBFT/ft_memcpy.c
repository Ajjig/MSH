/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:01:32 by majjig            #+#    #+#             */
/*   Updated: 2021/11/11 18:03:07 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dst;

	if (dest == NULL && src == NULL)
		return (NULL);
	dst = (char *) dest;
	while (n--)
		*dst++ = *(char *)src++;
	return (dest);
}
