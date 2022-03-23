#include "minishell.h"

char	*__cd__(t_command *command, t_envlist *lst)
{
	char	*wd;
	int		ret;
	char	*user;

	if (command->args && (command -> args[0] == NULL || ft_strcmp(command -> args[0], "~") == 0))
	{
		user = getenv("USER");
		chdir("/Users/");
		ret = chdir(user);
		if (ret != 0)
			puts("cd: no such file or directory");
		return NULL;
	}
	else
		ret = chdir(command -> args[0]);
	wd = getcwd(NULL, 0);
	if (ret != 0)
		puts("cd: no such file or directory");
	else
	{
		free(command->args[0]);
		command->args[0] = ft_strjoin("PWD=", wd);
		__export(lst, command);
	}
	free(wd);
	return NULL;
}
