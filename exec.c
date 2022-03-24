#include "minishell.h"

void	__exec__(t_command *command, t_envlist *lst)
{
	if (command -> program == NULL)
		return ;
	else if (ft_strchr(command -> program, '/') && access(command -> program, F_OK) == -1)
		printf("%s: file/program not found\n", command -> program);
	else if (ft_strcmp(command -> program, _CD) == 0)
		command->exit_status = __cd__(command, lst);
	else if (ft_strcmp(command -> program, _PWD) == 0)
		command->exit_status = __cwd__();
	else if (ft_strcmp(command -> program, _ECHO) == 0)
		command->exit_status = __echo(command);
	else if (ft_strcmp(command -> program, _ENV) == 0)
		command->exit_status = __env(lst);
	else if (ft_strcmp(command -> program, _EXPORT) == 0)
		command->exit_status = __export(lst, command);
	else if (ft_strcmp(command -> program, _UNSET) == 0)
		command->exit_status = __unset(command, lst);
	else if (command -> program)
		exeve_handler(command, lst);
}
