#include "minishell.h"

int	__cwd__(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		chdir("..");
		cwd = getcwd(NULL, 0);
	}
	ft_putendl_fd(cwd, STDOUT_FILENO);
	free(cwd);
	return 0;
}
