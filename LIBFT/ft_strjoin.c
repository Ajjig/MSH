/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:06:36 by majjig            #+#    #+#             */
/*   Updated: 2022/03/02 15:27:57 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*cat;
	int		total;

	str = (char *) s1;
	cat = (char *) s2;
	if (s1 == NULL)
		return (ft_strdup(cat));
	total = ft_strlen(str) + ft_strlen(cat) + 1;
	str = (char *) malloc(total * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, total);
	ft_strlcat(str, s2, total);
	return (str);
}
