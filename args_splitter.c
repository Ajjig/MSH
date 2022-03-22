#include "minishell.h"

int	get_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
		i = 0;
	if (str[i] == DOUBLE_QUOTE)
		while (str[++i] != DOUBLE_QUOTE)
			len++;
	else if (str[i] == SINGLE_QUOTE)
		while (str[++i] != SINGLE_QUOTE)
			len++;
	if (ft_strchr(REDIRECTIONS, str[i]))
	{
		len = 1;
		if (str[i] == str[i + 1])
			len ++;
	}
	else
		while (str[i] && !ft_strchr(WHITE_SPACES, str[i]) && !ft_strchr(REDIRECTIONS, str[i]) && !ft_strchr("\"'", str[i]))
			len += (i++ * 0) + 1;
	return (len);
}

static char	*trimmer(char *str)
{
	int		i;
	int		len;
	char	*ret;
	bool	is;

	len = get_len(str);
	i = 0;
	is = false;
	ret = (char *) malloc (len + 1);
	if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
		is = true;
	while (i < len)
	{
		while (str[i + 1] == -1)
			str++;
		if (is == false)
			ret[i] = str[i];
		else if (str[i + 1] != str[0])
			ret[i] = str[i + 1];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static int	count_words(char *str)
{
	int		words;
	int		i;
	char	*tmp;

	words = 0;
	i = 0;
	while (str[i])
	{
		words++;
		tmp = trimmer(str + i);
		if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
			i += 2;
		i += ft_strlen(tmp);
		while (str[i] && ft_strchr(WHITE_SPACES, str[i]))
			i++;
		free(tmp);
	}
	return words;
}

char	**args_splitter(char *str)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = check_quotes(str);
	if (str == NULL)
	{
		puts("Error:\n	expected \" or '");
		return (NULL);
	}
	ret = (char **) malloc ((count_words(str) + 1) * sizeof(char *));
	while (str[i])
	{
		ret[j] = trimmer(str + i);
		if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
			i += 2;
		i += ft_strlen(ret[j++]);
		while (str[i] && ft_strchr(WHITE_SPACES, str[i]))
			i++;
	}
	ret[j] = NULL;
	return ret;
}
