#include "minishell.h"

void	__exec__(t_command *command)
{
	char	*output;

	if (command -> program == NULL)
		return ;
	else if (ft_strcmp(command -> program, _CD) == 0)
		output = __cd__(command);
	else if (ft_strcmp(command -> program, _PWD) == 0)
		output = __cwd__(command);
}
