#include "minishell.h"

char	*is_builtin(char *cmd)
{
	static char	*all[] = {"echo", "cd", "pwd",
		"export", "unset", "env", "exit"};
	int			i;

	i = 0;
	while (i < 7)
		if (ft_strcmp(all[i++], cmd) == 0)
			return (all[--i]);
	printf("%s: command not found.\n", cmd);
	return (NULL);
}
