#include "minishell.h"

void	put_error(char **buff, int x)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen("Minishell $ ");
	while (i < x)
		len += ft_strlen(buff[i++]);
	write(1, "    ", 4);
	while (len-- > 4)
		write(1, "\x1b[32m~", ft_strlen("\x1b[32m~"));
	printf("\x1b[31m~^\nInvalid error:\n\x1b[37m\n");
}

bool	is_redirection(char *str)
{
	return (!ft_strcmp(str, RED_APPEND) || !ft_strcmp(str, ">")||
		!ft_strcmp(str, "|") || !ft_strcmp(str, "<"));
}

bool	error_checker(char **buff)
{
	int	i;

	i = 0;
	if (buff == NULL)
		return (false);
	while (buff[i])
	{
		if (is_redirection(buff[i]) && buff[i + 1] == NULL)
			return (put_error(buff, i + 1), false);
		if (is_redirection(buff[i]) && is_redirection(buff[i + 1]))
			return (put_error(buff, i + 1), false);
		i++;
	}
	return (true);
}
