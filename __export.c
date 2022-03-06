#include "minishell.h"

char *__export(t_envlist *lst, t_command *command)
{
	t_envlist *tmp;
	char *tofree;

	tmp = lst;
	if (!command->args)
		return NULL;

	while (tmp)
	{
		if (!strncmp(command->args[0], tmp->var_name, ft_strlen(tmp->var_name)) && (command->args[0][ft_strlen(tmp->var_name)] == '=' || command->args[0][ft_strlen(tmp->var_name)] == '+'))
		{
			if (command->args[0][ft_strlen(tmp->var_name)] == '+')
			{
				tofree = tmp->var_content;
				tmp->var_content = ft_strjoin(tmp->var_content, &command->args[0][ft_strlen(tmp->var_name)+2]);
				free(tofree);
			}
			else
				tmp->var_content = ft_strdup(&command->args[0][ft_strlen(tmp->var_name) + 1]);
			return NULL;
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(&lst, ft_lstnew(command->args[0]));
	return NULL;
}
