#include "minishell.h"

char	*str_delete(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char *) malloc (ft_strlen(str) + 1);
	while (str[j])
	{
		while (str[j] && str[j] == -1)
			j++;
		ret[i++] = str[j++];
	}
	ret[i] = 0;
	return (ret);
}

char	*check_quotes(char	*str)
{
	int	count1;
	int	count2;
	int	i;

	count2 = 0;
	count1 = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == DOUBLE_QUOTE && count1 % 2 == 0)
		{
			if (ft_strchr("\"'", str[i + 1]))
				str[i] = -1;
			count2++;
		}
		if (str[i] == SINGLE_QUOTE && count2 % 2 == 0)
		{
			if (ft_strchr("\"'", str[i + 1]))
				str[i] = -1;
			count1++;
		}
		i++;
	}
	if (count1 % 2 != 0 || count2 % 2 != 0)
		return NULL;
	return (str_delete(str));
}
