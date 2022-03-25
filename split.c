/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majjig <majjig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:05:13 by majjig            #+#    #+#             */
/*   Updated: 2022/03/25 23:31:31 by majjig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_alloc_fill(char *src, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dest = (char *) malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static char	*ft_alloc_fill_2(char *src, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dest = (char *) malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split_smart(char const *s, char c)
{
	int		j;
	int		words;
	char	**str;

	if (s == NULL)
		return (NULL);
	words = 3;
	str = (char **) malloc(words * sizeof(char *));
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[j++] = ft_alloc_fill((char *) s, c);
			while (*(s + 1) && *(s + 1) != c)
				s++;
		}
		else
		{
			str[j++] = ft_alloc_fill_2((char *)++s, c);
			break ;
		}
		s++;
	}
	return (str[j] = NULL, str);
}
