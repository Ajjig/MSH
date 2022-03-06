#include "minishell.h"

char	*__cd__(t_command *command)
{
	char	*wd;
	int		ret;
	char	*user;

	if (command -> args == NULL || ft_strcmp(command -> args[0], "~") == 0)
	{
		user = getenv("USER");
		chdir("/Users/");
		chdir(user);
		return NULL;
	}
	wd = getcwd(NULL, 0);
	ret = chdir(command -> args[0]);
	if (ret != 0)
		puts("cd: no such file or directory");
	return NULL;
}
