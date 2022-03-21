#include "minishell.h"

char *__echo(t_command *commad)
{
	int i;
	int tablen;

	tablen = ft_tab_len(commad->args);
	i = 0;
	if (!commad->args)
	{
		if (commad->options)
			return NULL;
		else
			return (printf("\n"), NULL);
	}
	else if (commad->options && !ft_strcmp(commad->options, "-n"))
	{
		while (i++ < tablen-1)
			printf("%s ", commad->args[i]);
		return NULL;
	}
	else if (!commad->options && commad->args)
	{
		while (i < tablen)
		{
			printf("%s ", commad->args[i]);
			i++;
		}
		printf("\n");
		return NULL;
	}
	return NULL;
}
