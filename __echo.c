#include "minishell.h"

char *__echo(t_command *commad)
{
	int i;
	int tablen;

	tablen = ft_tab_len(commad->args);
	i = 0;
	if (!commad->args[0])
	{
		if (!commad->options)
			printf("\n");
	}
	else if (commad->options && !ft_strcmp(commad->options, "-n"))
	{
		while (i < tablen-1)
			printf("%s ", commad->args[i++]);
		if (tablen >= 1)
			printf("%s", commad->args[i]);
	}
	else if (!commad->options && commad->args)
	{
		while (i < tablen-1)
			printf("%s ", commad->args[i++]);
		if (tablen >= 1)
			printf("%s\n", commad->args[i]);
	}
	return NULL;
}
