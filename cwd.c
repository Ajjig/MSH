#include "minishell.h"

char	*__cwd__(t_command *command)
{
	char	*cwd;

	command += 0;
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		chdir("..");
		cwd = getcwd(NULL, 0);
	}
	ft_putendl_fd(cwd, STDOUT_FILENO);
	free(cwd);
	return cwd;
}
