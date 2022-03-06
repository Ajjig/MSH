#include "minishell.h"

void	__exec__(t_command *command, t_envlist *lst)
{
	char	*output;

	if (command -> program == NULL)
		return ;
	else if (ft_strcmp(command -> program, _CD) == 0)
		output = __cd__(command, lst);
	else if (ft_strcmp(command -> program, _PWD) == 0)
		output = __cwd__(command);
	else if (ft_strcmp(command -> program, _ECHO) == 0)
		output = __echo(command);
	else if (ft_strcmp(command -> program, _ENV) == 0)
		output = __env(lst);
	else if (ft_strcmp(command -> program, _EXPORT) == 0)
		output = __export(lst, command);
	else if (command -> program)
		exeve_handler(command, lst);

}
