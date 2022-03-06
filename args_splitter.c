#include "minishell.h"


static char	*ft_alloc_fill(char *src)
{
	int		i;
	char	*dest;
	bool	is;

	i = 0;
	is = false;
	if (src[i] && ft_strchr(REDIRECTIONS, src[i]))
	{
		i = 1;
		is = true;
		if (src[i] && src[i] == src[i - 1])
			i++;
	}
	else if (src[i])
		while (src[i] && !ft_strchr(WHITE_SPACES, src[i]) && !ft_strchr(REDIRECTIONS, src[i]))
			i++;
	dest = (char *) malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] && !ft_strchr(WHITE_SPACES, src[i]))
	{
		if (!is && ft_strchr(REDIRECTIONS, src[i]))
			break ;
		dest[i] = src[i];
		i++;
		if (is && (src[i] != src[i - 1] || i == 2))
			break ;
	}
	dest[i] = 0;
	return (dest);
}

static int	ft_count_words(char *str)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (!ft_strchr(WHITE_SPACES, *str))
		{
			words++;
			while (*str && !ft_strchr(WHITE_SPACES, *str))
			{
				if (ft_strchr(REDIRECTIONS, *str))
				{
					words ++;
					str++;
					if (*str == *(str - 1))
						str++;
					break;
				}
				str++;
			}
			continue ;
		}
		str++;
	}
	return (words + 1);
}

static int	ft_check_is_alloc(char **str, int j)
{
	if (str[j] == NULL)
	{
		while (j)
			free(str[--j]);
		free(str);
		return (0);
	}
	return (1);
}

char	**args_splitter(char *s)
{
	int		j;
	int		words;
	char	**str;

	if (s == NULL)
		return (NULL);
	words = ft_count_words((char *) s);
	str = (char **) malloc(words * sizeof(char *));
	j = 0;
	while (*s)
	{
		if (!ft_strchr(WHITE_SPACES, *s))
		{
			str[j] = ft_alloc_fill((char *) s);
			if (!(ft_check_is_alloc(str, j++)))
				return (NULL);
			if (ft_strchr(REDIRECTIONS, *s))
			{
				if (*(s + 1) == *s)
					s ++;
			}
			else
				while (*(s + 1) && !ft_strchr(WHITE_SPACES, *(s + 1)) && !ft_strchr(REDIRECTIONS, *(s + 1)))
					s++;
		}
		s++;
	}
	str[j] = NULL;
	return (str);
}
