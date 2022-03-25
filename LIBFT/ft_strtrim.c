/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:09:51 by majjig            #+#    #+#             */
/*   Updated: 2022/03/25 20:56:23 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*str;
	int		start;
	int		end;

	s = (char *) s1;
	start = 0;
	if (set == NULL || s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (ft_strrchr(set, s[start]) && end >= start)
		start++;
	while (ft_strrchr(set, s[end]) && end >= start)
		end--;
	str = (char *) malloc(end - start + 2);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], end - start + 2);
	return (str);
}
