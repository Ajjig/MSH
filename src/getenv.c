/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajjig <ajjig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:15:03 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/06/21 00:38:47 by ajjig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*finder(char *find, t_envlist *lst)
{
	if (!ft_strcmp(find, "?"))
		return (ft_itoa(g_variable.g_exites));
	while (lst)
	{
		if (!ft_strcmp(find, lst -> var_name))
		{
			free(find);
			return (ft_strdup(lst -> var_content));
		}
		lst = lst -> next;
	}
	return (NULL);
}

char	*cutter(char *tofind)
{
	int		len;
	char	*ret;
	int		i;

	i = 0;
	len = 0;
	while (tofind[len] && (ft_isalnum(tofind[len])
			|| tofind[len] == '_' || tofind[len] == '?'))
		len++;
	ret = (char *) malloc (len + 1);
	while (i < len)
	{
		ret[i] = tofind[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*joiner(char *s1, char *s2, t_envlist *lst)
{
	int		len;
	int		i;
	char	*ret;

	i = 0;
	len = 0;
	s2 = finder(s2, lst);
	if (s2 == NULL)
	{
		free (s2);
		return (s1);
	}
	ret = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
		ret[i++] = s2[len++];
	ret[i] = 0;
	free(s1);
	free(s2);
	return (ret);
}

char	*add_char(char *s, char c)
{
	int		i;
	char	*ret;

	i = 0;
	if (s == NULL)
	{
		ret = (char *) malloc (2 * sizeof(char));
		ret[0] = c;
		ret[1] = 0;
		return (ret);
	}
	ret = (char *) malloc (ft_strlen(s) + 2);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i++] = c;
	ret[i] = 0;
	free(s);
	return (ret);
}

char	*__get_env(char *read, t_envlist *lst, int i)
{
	char	*ret;
	int		count1;
	int		count2;
	char	*tmp;

	count2 = 0;
	count1 = 0;
	ret = (char *) malloc (2 * sizeof(char));
	*ret = 0;
	while (read[i])
	{
		if (read[i] == SINGLE_QUOTE && count2 % 2 == 0)
			count1 ++;
		if (read[i] == DOUBLE_QUOTE && count1 % 2 == 0)
			count2 ++;
		if (read[i] == '$' && count1 % 2 == 0)
		{
			tmp = cutter(&read[++i]);
			i += ft_strlen(tmp);
			ret = joiner(ret, tmp, lst);
		}
		else
			ret = add_char(ret, read[i++]);
	}
	return (free(read), ret);
}
