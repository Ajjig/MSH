/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:00:06 by majjig            #+#    #+#             */
/*   Updated: 2021/11/07 16:16:01 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (size + 1);
}

static void	ft_itoa_fill(char *dest, int nb, int len)
{
	int	end;

	end = 0;
	dest[len] = 0;
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
		end = 1;
	}
	while (len-- > end)
	{
		dest[len] = nb % 10 + 48;
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*buff;

	len = ft_get_size(n);
	buff = (char *) malloc(len + 1);
	if (buff == NULL)
		return (0);
	if (n == 0)
		ft_strlcpy(buff, "0", 2);
	if (n == -2147483648)
		ft_strlcpy(buff, "-2147483648", 12);
	else
		ft_itoa_fill(buff, n, len);
	return (buff);
}
