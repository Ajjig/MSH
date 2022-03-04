#include "minishell.h"

char *__echo(t_command *commad)
{
	if (!commad->args)
	{
		if (commad->options)
			return NULL;
		else
			return (printf("\n"), ft_strdup("\n"));
	}
	else if (commad->options && !ft_strcmp(commad->options, "-n"))
	{
		printf("%s", commad->args);
		return ft_strdup(commad->args);
	}
	else if (!commad->options && commad->args)
	{
		printf("%s\n", commad->args);
		return ft_strdup(commad->args);
	}
	return NULL;
}
