#include "minishell.h"

int	parser(t_command *command, char **buff,  int *i, int *ai)
{
	if (buff[*i] && *i == 1 && !ft_strcmp(buff[*i], "-n") && !ft_strcmp(_ECHO, command -> program))
	{
		command -> options = ft_strdup(buff[*i]);
		*i += 1;
	}
	if (buff[*i] && *i > 0 && !ft_strchr(REDIRECTIONS, buff[*i][0]))
	{
		command -> args[*ai] = ft_strdup(buff[*i]);
		*ai += 1;
	}
	return (0);
}
